class Solution
{
public:
    std::string map(const int digit, const char one, const char five, const char ten) noexcept
    {
        if (digit == 0)
            return "";
        else if (digit == 1)
            return std::string(&one, 1);
        else if (digit < 4)
            return std::string(&one, 1) + map(digit - 1, one, five, ten);
        else if (digit == 4)
            return std::string(&one, 1) + std::string(&five, 1);
        else if (digit < 9)
            return std::string(&five, 1) + map(digit - 5, one, five, ten);
        else 
            return std::string(&one, 1) + std::string(&ten, 1);
    }
    
    string intToRoman(int num)
    {
        std::string res("");
        
        int n = num / 1000;
        for (size_t i = 0; i < n; ++i) res += 'M';
        num -= 1000 * n;
        
        n = num / 100;
        res += map(n, 'C', 'D', 'M');
        num -= 100 * n;
        
        n = num / 10;
        res += map(n, 'X', 'L', 'C');
        num -= 10 * n;
        
        n = num;
        res += map(n, 'I', 'V', 'X');
        
        return res;
    }
};