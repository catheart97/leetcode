#include <vector>
#include <bitset>

class Solution
{
public:
    bool validUtf8(vector<int>& data)
    {        
        int cl{0};
        for (size_t i = 0; i < data.size(); ++i)
        {
            const uint8_t c = static_cast<uint8_t>(data[data.size() - i - 1]);
            if (cl == 0 && !(c >> 7)) continue;
            else if (uint8_t t = c << cl + 1; !(t >> 7) && ((int8_t(c) >> 7 - cl) == int8_t(0xff)) && cl    ) cl = 0;
            else if (uint8_t t = c <<      1; !(t >> 7) && ((int8_t(c) >> 7     ) == int8_t(0xff)) && cl < 3) cl++;
            else return false;
        }
        return cl == 0;
    }
};

int main()
{
    Solution().validUtf8(std::vector<int>{
        197, 130, 1
    });
    return 0;
}