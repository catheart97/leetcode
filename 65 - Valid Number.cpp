class Solution
{    
public:
    bool isNumber(string s)
    {
        auto isDigit = [&s](const int i) {
            return 48 <= s[i] && s[i] <= 57;
        };
        
        int i = 0;
        
        if (s[i] == '+' || s[i] == '-') ++i;  // sign test
        
        if (s[i] == '.') // case 3
        {
            ++i;
            if (!isDigit(i++)) return false;
            while (isDigit(i)) { ++i; }
        }
        else // case 1 and 2 + integer
        {
            
            if (!isDigit(i++)) return false;
            while (isDigit(i)) { ++i; }
            if (s[i] == '.') { ++i; }
            while (isDigit(i)) { ++i; }
        }
        
        if (i == s.size())
            return true;
        else if (!(s[i] == 'e' || s[i] == 'E'))
            return false;
        
        ++i;
        if (s[i] == '+' || s[i] == '-') ++i;  // sign test
        if (!isDigit(i++)) return false;
        while (isDigit(i)) { ++i; }
        
        return i == s.size();
    }
};