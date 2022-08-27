class Solution
{
public:
    bool areNumbersAscending(string s)
    {
        int c_num = -1;
        
        for (size_t i = 0; i < s.size(); ++i)
        {
            if (char v = s[i]; v >= 48 && v <= 57)
            {
                int n_num = std::atoi(&s[i]);
                if (n_num > 9)
                    ++i;
                if (n_num <= c_num)
                    return false;
                else 
                    c_num = n_num;
            }
        }
        return true;
    }
};