#include <string>
#include <string_view>
#include <iostream>

class Solution
{
public:
    std::string reverseWords(std::string s)
    {
        std::string_view sv(s);
        while (1)
        {
            // find next occurance of ' '
            size_t e = sv.find(' ');
            if (e == std::string::npos) e = sv.size();
            
            // swap sv up to e
            char * const data{const_cast<char*>(sv.data())};
            for (size_t i = 0; i < e / 2; ++i)
                std::swap(data[i], data[e - i - 1]);
            
            // if last word exit here
            if (e == sv.size()) break;
            sv = sv.substr(e + 1);
        }
        return std::move(s);
    }
};


int main()
{
    std::string s = "abcde jgh";

    std::cout << Solution().reverseWords(s) << std::endl;

    return 0;
}