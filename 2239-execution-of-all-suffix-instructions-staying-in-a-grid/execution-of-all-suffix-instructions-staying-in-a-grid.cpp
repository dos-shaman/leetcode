class Solution {
public:
int val;
bool is_valid(int n,int r,int c, string &s,int index)
{
    if(r>=n||c>=n||r<0||c<0||index>=s.size())
     return false;
     return true;
}
void dfs(int n,int r,int c, string &s,int index)
{
    if(r>=n||c>=n||r<0||c<0||index>=s.size())
     return;
    
      if(s[index]=='R'&&is_valid(n,r,c+1,s,index))//check if present index is valid and then go for +1 index
      {
           val++;
         dfs(n,r,c+1,s,index+1);
      }
      if(s[index]=='D'&&is_valid(n,r+1,c,s,index))
      {
           val++;
         dfs(n,r+1,c,s,index+1);
      }
      if(s[index]=='L'&&is_valid(n,r,c-1,s,index))
      {
           val++;
         dfs(n,r,c-1,s,index+1);
      }
      if(s[index]=='U'&&is_valid(n,r-1,c,s,index))
      {
           val++;
         dfs(n,r-1,c,s,index+1);
      }
}
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        vector<int>ans;
        for(int i=0;i<s.size();i++)
        {
            val=0;
            dfs(n,startPos[0],startPos[1],s,i);
            ans.push_back(val);//since val will be incre 1 time extra even if the next cell is valid
        }
        return ans;
    }
};