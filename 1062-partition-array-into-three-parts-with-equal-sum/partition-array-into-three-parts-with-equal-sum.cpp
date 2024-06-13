class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
     int sum=0,sum1=0,count=0;
     for(int i=0;i<arr.size();i++)
        sum+=arr[i];
    if(sum%3!=0)
     return false;
     sum/=3;
    int i=0;
    while(i<arr.size())
    {
         sum1+=arr[i];
        if(sum1==sum)
        {
            count++;
            sum1=0;
            if(count==3)
              return (i==arr.size()-1 || count==3);
        }
       i++;
    } 
    return false; 
    }
};