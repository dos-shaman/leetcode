class Solution {
public:
    int countEven(int num) {
        int c=0;
         for(int i=2;i<=num;i++){
             int sum=0;
             int k=i;
             while(k>0){
                 int g=k%10;
                 sum+=g;
                 k=k/10;
             }
             if(sum%2==0){
                 c++;
             }
         }
         return c;
        
    } // please upvote guys
};