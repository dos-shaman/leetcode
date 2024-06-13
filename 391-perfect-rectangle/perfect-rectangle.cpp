namespace std {
    template <>
    struct hash<pair<int, int>> {
        size_t operator()(const pair<int, int>& p) const {
            return hash<int>{}(p.first) ^ (hash<int>{}(p.second) << 1); // Combine the two hash values
        }
    };
}

class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        if (rectangles.size() == 1) return true;

        unordered_map<pair<int, int>, pair<int, int>, std::hash<pair<int, int>>> recs;
        int limleft = numeric_limits<int>::max();
        int limbot = numeric_limits<int>::max();
        int width = 0, height = 0, areasum = 0;

        
        for (const auto& rec : rectangles) {
            limleft = min(limleft, rec[0]);
        }
        for (const auto& rec : rectangles) {
            if (rec[0] == limleft) {
                limbot = min(limbot, rec[1]);
            }
        }

        
        for (const auto& rec : rectangles) {
            auto corner = make_pair(rec[0], rec[1]);
            if (recs.count(corner)) return false;
            recs[corner] = make_pair(rec[2], rec[3]);
        }

        
        pair<int, int> up(limleft, limbot), right(limleft, limbot);
        while (recs.count(up) || recs.count(right)) {
            if (recs.count(up)) {
                height += recs[up].second - up.second;
                up = {limleft, recs[up].second};
            }
            if (recs.count(right)) {
                width += recs[right].first - right.first;
                right = {recs[right].first, limbot};
            }
        }

        int limright = limleft + width, limtop = limbot + height;
        stack<pair<int, int>> squaresfilter;
        squaresfilter.push({limleft, limbot});

        
        while (!squaresfilter.empty()) {
            auto curr = squaresfilter.top();
            squaresfilter.pop();
            if (recs.count(curr)) {
                if (curr.first < limleft || curr.second < limbot || recs[curr].first > limright || recs[curr].second > limtop) {
                    return false;
                }
                areasum += (recs[curr].first - curr.first) * (recs[curr].second - curr.second);
                squaresfilter.push({curr.first, recs[curr].second});
                squaresfilter.push({recs[curr].first, curr.second});
                recs.erase(curr);
            }
        }

        return areasum == width * height && recs.empty() && areasum != 0;
    }
};