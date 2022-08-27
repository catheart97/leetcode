class Solution
{
    // plain data
private:    
    std::string onekeys[9] = {
        " One", " Two", " Three", " Four", " Five", " Six", " Seven", " Eight", " Nine"
    };
    
    std::string tenkeys[9] = {
        " Ten", " Twenty", " Thirty", " Forty", " Fifty", " Sixty", " Seventy", " Eighty", " Ninety"
    };
    
    std::string keywords[4] = {
        " Thousand", " Million", " Billion"
    };
    
    std::string specialkeys[9] = {
        " Eleven", " Twelve", " Thirteen", " Fourteen", " Fifteen", " Sixteen", " Seventeen", " Eighteen", " Nineteen"
    };
    
    // helper methods
private:
    std::string digitToWord(const int digit)
    {
        return onekeys[digit - 1];
    }
    
    std::string tenDigitToWord(const int digit)
    {
        return tenkeys[digit - 1];
    }
    
    std::string specialNumber(int twodigits)
    {
        return specialkeys[twodigits - 11];
    }
    
public:
    string numberToWords(int num)
    {
        if (!num) return "Zero";   
        
        std::string res;

        for (size_t i = 0; i < 4; ++i)
        {
            int tmp = num % 1000;
            
            // add keyword if number is non-zero
            if (tmp && i) res = keywords[i - 1] + res;
            
            // compute first digit
            int fd = tmp / 100;
            tmp %= 100;
            
            // check for any special two digit number (eg. twelve)
            if (tmp > 10 && tmp < 20)
            {
                res = specialNumber(tmp) + res;
            }
            else 
            {
                // no special case => compute second and third digit
                int sd = tmp / 10;
                tmp %= 10;
                
                if (tmp) // tmp is now third digit
                    res = digitToWord(tmp) + res;
                if (sd)
                    res = tenDigitToWord(sd) + res;

            }

            if (fd)
                res = digitToWord(fd) + " Hundred" + res;
            
            num /= 1000;
        }
        return res.substr(1, std::string::npos);
    }
};