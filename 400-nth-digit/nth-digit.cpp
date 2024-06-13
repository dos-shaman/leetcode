class Solution {
public:
    int findNthDigit(int n) {
        int g=pow(2,31)-1;
        vector<long long> num;
        num.push_back(0);
        long long val=0;
        int i=1;
        int c=1;
        while(val<g)
        {
            long h=9*i;
            i=i*10;
            val=h*c;
            num.push_back(val);
            c++;
        }
        long long int sum=0;
        for(i=0;i<num.size();i++)
        {
            sum=sum+num[i];
            if(n<=sum)
            {
                break;
            }
        }
        n=n-(sum-num[i]);
        int f=n%i;
        if(f==0)
        {
            f=i-1;
        }
        else
        f=f-1;
        if(n%i==0)
        n=(n/i)-1;
        else
        n=n/i;
        int q=1;
        for(int z=1;z<i;z++)
        {
            q=q*10;
        }
        q=q+n;
        string str=to_string(q);
        char gi=str[f];
        return gi-'0';
    }
};