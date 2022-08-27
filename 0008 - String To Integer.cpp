class Solution
{
public:
    int myAtoi(string s) {
        long res = 0;
        
        // read whitespaces
        int i = 0;
        while(s[i] == ' ') ++i;
        
        char sign = 1;
        if (s[i] == '-')
        {
            sign = -1;
            ++i;
        }
        else if (s[i] == '+') ++i;
        
        
        for (; i < s.size(); ++i)
        {
            if (char v = s[i]; v >= 48 && v <= 57)
            {
                res = res * 10.0 + (v - 48);
                
                if (sign > 0)
                {
                    if (res > 2147483647L)
                        res = 2147483647L;
                }
                else
                {
                    if (res > 2147483648L)
                        res = 2147483648L;
                }
            }
            else
            {
                break;
            }
        }
        
        return static_cast<int>(sign * res);
    }
};