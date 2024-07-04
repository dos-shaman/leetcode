const int MAX_N=50;
int pos[MAX_N],heavy[MAX_N],subtree[MAX_N],depth[MAX_N],head[MAX_N],par[MAX_N],full[MAX_N],half[MAX_N],cur_pos;

void init(int n)
{
    for(int i=0;i<n;++i)
    {
        pos[i]=heavy[i]=-1;
        subtree[i]=depth[i]=0;
        head[i]=par[i]=i;
        half[i]=full[i]=1e9;
    }
    cur_pos=0;
}

void dfs(int node,int parent,vector<int> adj[])
{
    subtree[node]=1;
    for(auto &v:adj[node])
    {
        if(v!=parent)
        {
            depth[v]=depth[node]+1;
            par[v]=node;
            dfs(v,node,adj);
            subtree[node]+=subtree[v];
            if(heavy[node]==-1)
            {
                heavy[node]=v;
            }
            else
            {
                if(subtree[v]>subtree[heavy[node]])
                {
                    heavy[node]=v;
                }
            }
        }
    }
}

void hld(int node,int chain,vector<int> adj[])
{
    head[node]=chain;
    pos[node]=cur_pos++;
    if(heavy[node]!=-1)
    {
        hld(heavy[node],chain,adj);
    }
    for(auto &v:adj[node])
    {
        if(v!=par[node]&&v!=heavy[node])
        {
            hld(v,v,adj);
        }
    }
}

void dfs(int node,vector<int> adj[],vector<int> &freq,vector<int> &price)
{
    half[node]=freq[node]*(price[node]/2);
    full[node]=freq[node]*price[node];
    for(auto &v:adj[node])
    {
        if(v!=par[node])
        {
            dfs(v,adj,freq,price);
            half[node]+=full[v];
            full[node]+=min(half[v],full[v]);
        }
    }
}

class SegmentTree
{
    
private:
    
    vector<int> seg,lazy;
    
public:
    
    SegmentTree(int n)
    {
        seg.resize(4*n+1);
        lazy.resize(4*n+1);
    }
    
    void update(int ind,int lo,int hi,int l,int r)
    {
        if(lazy[ind]!=0)
        {
            seg[ind]+=(hi-lo+1)*lazy[ind];
            if(lo!=hi)
            {
                lazy[2*ind+1]+=lazy[ind];
                lazy[2*ind+2]+=lazy[ind];
            }
            lazy[ind]=0;
        }
        if(l>hi||lo>r)
        {
            return;
        }
        if(l<=lo&&hi<=r)
        {
            seg[ind]+=(hi-lo+1);
            if(lo!=hi)
            {
                lazy[2*ind+1]++;
                lazy[2*ind+2]++;
            }
            return;
        }
        int mid=lo+(hi-lo)/2;
        update(2*ind+1,lo,mid,l,r);
        update(2*ind+2,mid+1,hi,l,r);
        seg[ind]=seg[2*ind+1]+seg[2*ind+2];
    }
    
    int query(int ind,int lo,int hi,int i)
    {
        if(lazy[ind]!=0)
        {
            seg[ind]+=(hi-lo+1)*lazy[ind];
            if(lo!=hi)
            {
                lazy[2*ind+1]+=lazy[ind];
                lazy[2*ind+2]+=lazy[ind];
            }
            lazy[ind]=0;
        }
        if(lo==hi)
        {
            return seg[ind];
        }
        int mid=lo+(hi-lo)/2;
        if(i<=mid)
        {
            return query(2*ind+1,lo,mid,i);
        }
        return query(2*ind+2,mid+1,hi,i);
    }
    
};

class Solution {
public:
int minimumTotalPrice(int n,vector<vector<int>> &edges,vector<int> &price,vector<vector<int>> &trips)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    init(n);
    vector<int> adj[n],freq(n);
    for(auto &edge:edges)
    {
        int u=edge[0],v=edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0,0,adj);
    hld(0,0,adj);
    SegmentTree st(n);
    for(auto &trip:trips)
    {
        int u=trip[0],v=trip[1];
        while(head[u]!=head[v])
        {
            if(depth[head[u]]<depth[head[v]])
            {
                swap(u,v);
            }
            st.update(0,0,n-1,pos[head[u]],pos[u]);
            u=par[head[u]];
        }
        if(depth[u]<depth[v])
        {
            swap(u,v);
        }
        st.update(0,0,n-1,pos[v],pos[u]);
    }
    for(int i=0;i<n;++i)
    {
        freq[i]=st.query(0,0,n-1,pos[i]);
    }
    dfs(0,adj,freq,price);
    return min(half[0],full[0]);
}
};