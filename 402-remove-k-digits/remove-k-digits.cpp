class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;
        int n=num.size();

        for(int i=0;i<n;i++){
            while(!st.empty()  && k>0 && st.top()>num[i]){
                k--;
                st.pop();
            }
            st.push(num[i]);

        }

        while(k>0 && !st.empty()) st.pop(),k--;
        string res="";
          while (!st.empty()) {
            res += st.top();
            st.pop();
        }

        reverse(res.begin(), res.end());
        int i=0;
        int q=res.size();

        while(i<q && res[i]=='0') i++;
        if(i==q) return "0";
        else{
          return  res.substr(i,q-i+1);
        }
    }
};