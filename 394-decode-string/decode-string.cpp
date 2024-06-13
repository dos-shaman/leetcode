class Solution {
public:
    string decodeString(string s) {
        string ret="";

        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(s[i]==']'){
                string l="";
                while(st.top()!='['){
                    l=st.top()+l;
                    st.pop();
                }
                st.pop();
                int n=0;
                int cv=1;
                while(!st.empty() && st.top()>='0' && st.top()<='9'){
                    n=n+cv*(int(st.top() - '0'));
                    cv=cv*10;
                    st.pop();
                }
                while(n-->0){
                    for(int i=0;i<l.size();i++)
                        st.push(l[i]);
                }

            }else
                st.push(s[i]);
        }

        while(!st.empty()){
            ret=st.top()+ret;
            st.pop();
        }
        return ret;
    }
};