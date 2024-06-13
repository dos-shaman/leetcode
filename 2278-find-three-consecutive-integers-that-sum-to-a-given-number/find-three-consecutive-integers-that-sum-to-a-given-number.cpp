class Solution {
public:
    vector<long long> sumOfThree(long long num) 
    {
        vector<long long>ans;
	
        if((num % 3)  !=0 )
        return {};

        long long start = (num-3)/3;

        ans.push_back(start);
        ans.push_back(start+1);
        ans.push_back(start+2);

        return ans;    
    }
};