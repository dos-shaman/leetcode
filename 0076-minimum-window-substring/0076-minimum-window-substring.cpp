class Solution {
public:
    string minWindow(string s, string t) {
        
        int n = t.size();
        int m = s.size();
        int r=0,l=0,minl=INT_MAX;
        int count = 0;
        int sindex = -1;
        int hash[256] ={0};
        for(int i=0;i<n;i++){
            hash[t[i]]++;
        }
       while(r<m){
        hash[s[r]]--;
        if(hash[s[r]]>=0){
            count = count +1;
           // hash[s[r]]--;
        }
        while(count == n){
            if(r-l+1 < minl){
                minl = r-l+1;
                //starting index
                sindex = l;
            }
            hash[s[l]]++;  
            if(hash[s[l]]>0){
                count-- ;
            }
            l++;
        }
        r++;

       }
       return sindex==-1?"":s.substr(sindex,minl);
    }
};