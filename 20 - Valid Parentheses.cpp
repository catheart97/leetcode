class Solution
{
public:
    inline char openBracket(const char c)
    {
        return c == ')' ? c - 1 : c - 2;
    }
    
    bool isValid(string s)
    {       
        std::stack<char> history;
        
        for (char c : s)
        {
            if (c == '(' || c == '[' || c == '{')
            {
                history.push(c);
                continue;
            }
            else
            {
                if (history.empty() || history.top() != openBracket(c)) return false;
                history.pop();
            }
        }
        return history.empty();
    }
};