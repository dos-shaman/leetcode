class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        const int m = seats.size();
        int ans = 0;
        sort(seats.begin(),seats.end());
        sort(students.begin(),students.end());
        for(int i=0;i<m;++i){ans+=abs(seats[i]-students[i]);}
        return ans;
    }
};