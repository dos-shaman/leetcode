class Solution {
public:
    bool isSameAfterReversals(int num) {
        
        if(num==0){
            return true;
        }
        int digit=num%10;
        if(digit==0){
            return false;
        }
        return true;
    }
};