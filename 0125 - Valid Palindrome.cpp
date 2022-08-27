class Solution
{
public:
    
    inline bool isAlphaNumeric(const char v)
    {
        return (v >= 'a' && v <= 'z') || (v >= '0' && v <= '9'); 
    }
    
    bool isPalindrome(string s)
    {
        size_t i{0}, j{s.size() - 1}; 
        
        while (i < j)
        {
            char si = s[i];
            char sj = s[j];
            
            // lower case
            if (si >= 'A' && si <= 'Z')
                si = si - 'A' + 'a';
            if (sj >= 'A' && sj <= 'Z')
                sj = sj - 'A' + 'a';
                
            const bool alsi = isAlphaNumeric(si);
            const bool alsj = isAlphaNumeric(sj);
            
            if (alsi && alsj && si != sj)
            {
                return false;
            }
            else if (alsi == alsj)
            {
                ++i;
                --j;
                continue;
            }
            
            if (alsi)
            {
                --j;
            }
            else
            {
                ++i;
            }
        }
        
        return true;
    }
};