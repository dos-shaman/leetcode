class Solution {
public:
int find(int n,vector<int>&par)
{
    if(n==par[n])return n;
    return par[n]=find(par[n],par);
}
void join(int u,int v,vector<int>&size,vector<int>&par)
{
    int pu=find(u,par);
    int pv=find(v,par);
    if(pu==pv)return;
    if(size[pu]>size[pv])
    {
        size[pu]+=size[pv];
        par[pv]=pu;
    }else
    {
        size[pv]+=size[pu];
        par[pu]=pv;
    }
}
    vector<bool> friendRequests(int n, vector<vector<int>>& re, 
    vector<vector<int>>& req) {
        vector<int> size(n,1),par(n,0);
        for(int i=0;i<n;i++)par[i]=i;
        vector<bool> ans;
        for(auto i:req)
        {
            int f=1;
            for(auto j:re)
            {
                if((find(j[0],par)==find(i[0],par)&&find(j[1],par)==find(i[1],par))||(find(j[0],par)==find(i[1],par)&&find(j[1],par)==find(i[0],par)))
                {
                    f=0;
                }
            }
            if(f)
            {
                ans.push_back(true);
                join(i[0],i[1],size,par);
            }else
            {
                ans.push_back(false);
            }
        }
        return ans;
    }
};