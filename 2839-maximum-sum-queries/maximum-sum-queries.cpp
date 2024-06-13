class Solution {
public:
    vector<int> maximumSumQueries(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        vector<int> res;
        // meaning of sum_arr:
        // 0: sum of two; 1: first element; 2: second element; 3: the max first element to the right; 4: the max second elemnt to the right
        vector<tuple<int,int,int,int,int>> sum_arr;
        for(int i = 0; i < nums1.size(); ++i) {
            sum_arr.emplace_back(tuple<int,int,int,int,int>{nums1[i] + nums2[i], nums1[i], nums2[i], nums1[i], nums2[i]});
        }
        // search should start from the biggest sum end going to the smallest sum end. Whenever a tuple fits, break the loop and that's the tuple we want. (greedy)
        sort(sum_arr.begin(), sum_arr.end());
        
        // Fill in the 3rd and 4th elements of the tuples.
        if (sum_arr.size() > 1 )
            for(auto it = sum_arr.rbegin() + 1; it != sum_arr.rend(); ++it) {
                get<3>(*it) = max(get<3>(*it), get<3>(*(prev(it))));
                get<4>(*it) = max(get<4>(*it), get<4>(*(prev(it))));
            }
            
        for(int i = 0; i < queries.size(); ++i) {
            auto[ bit, eit ] = equal_range(
                sum_arr.begin(), sum_arr.end(), tuple<int,int,int,int,int>{queries[i][0] + queries[i][1], queries[i][0], queries[i][1], queries[i][0], queries[i][1]}
            );

            // !!!!!!! key: We should start not from the very end (with the biggest sum). 
            //              But from a place where at least max(first elements to the right) > first element of query and max(seconds elements to the right ) > second element of query
            auto start_it = min(
                lower_bound(sum_arr.begin(), sum_arr.end(), tuple<int,int,int,int,int>{0, 0, 0, queries[i][0], 0}, [](const auto& tp1, const auto& tp2){ return get<3>(tp1) >= get<3>(tp2);}),
                lower_bound(sum_arr.begin(), sum_arr.end(), tuple<int,int,int,int,int>{0, 0, 0, 0, queries[i][1]}, [](const auto& tp1, const auto& tp2){ return get<4>(tp1) >= get<4>(tp2);})
            );
            
            // the index to start the search, going left. (because the first (or second) elements to the right are all smaller than the first (or second) element of query)
            start_it = min( next(start_it), prev(sum_arr.end()) );
            if( eit == bit ) {
                if(bit == sum_arr.end()) {
                    res.push_back(-1);
                    continue;
                } else {
                    bool flag = false;
                    for(int j = start_it - sum_arr.begin(); j >= bit - sum_arr.begin(); --j) {
                        if(get<1>(sum_arr[j]) >= queries[i][0] && get<2>(sum_arr[j]) >= queries[i][1]) {
                            res.push_back(get<0>(sum_arr[j]));
                            flag = true;
                            break;
                        }
                    }
                    if(!flag)
                        res.push_back(-1);
                }            
            } else {
                bool flag = false;
                for(int j = start_it - sum_arr.begin(); j >= bit - sum_arr.begin(); --j) {
                    if(get<1>(sum_arr[j]) >= queries[i][0] && get<2>(sum_arr[j]) >= queries[i][1]) {
                        res.push_back(get<0>(sum_arr[j]));
                        flag = true;
                        break;
                    }
                }
                if(!flag)
                    res.push_back(-1);
            }
        }
        return res;
    }
};