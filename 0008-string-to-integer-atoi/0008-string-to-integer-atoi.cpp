class Solution {
public:
    int Atoi(string s, bool sign, int i = 0, int num = 0) {
        if(i >= s.length())
            return num;

        if(num > INT_MAX / 10 || (num == INT_MAX / 10 && s[i] - '0' > INT_MAX % 10))
            return INT_MAX; 

        if(num < INT_MIN / 10 || (num == INT_MIN / 10 && s[i] - '0' > -(INT_MIN % 10)))
            return INT_MIN;

        if(sign)
            num = (num * 10 + -(s[i] - '0'));
        else
            num = num * 10 + (s[i] - '0');
        return Atoi(s, sign, i+1, num);
    }

    int myAtoi(string s) {
       size_t firstNonSpace = s.find_first_not_of(" ");
       bool sign = false;

       if(firstNonSpace != std::string::npos)
            s.erase(0, firstNonSpace);

        if(s[0] == '-')
            sign = true;

        if(s[0] == '-' || s[0] == '+')
            s.erase(0, 1);

        size_t firstNonDigit = s.find_first_not_of("0123456789");
        if(firstNonDigit != std::string::npos)
            s = s.substr(0, firstNonDigit);

        if(s.length() == 0)
            return 0;

        return Atoi(s, sign);
    }
};