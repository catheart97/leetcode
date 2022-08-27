class Solution
{
public:
    int interpretLiteral(const char c)
    {
        if (c == 'I') return 1;
        if (c == 'V') return 5;
        if (c == 'X') return 10;
        if (c == 'L') return 50;
        if (c == 'C') return 100;
        if (c == 'D') return 500;
        if (c == 'M') return 1000;
        return 0; // not a valid literal.
    }
    
    int romanToInt(string s)
    {        
        int res{interpretLiteral(s[s.size() - 1])};
        int prev{res};
        for (size_t i = 1; i < s.size(); ++i)
        {
            const int next = interpretLiteral(s[s.size() - i - 1]);
            
            if (prev > next) 
                res -= next;
            else
                res += next;
            
            prev = next;
        }
        return res;
    }
};