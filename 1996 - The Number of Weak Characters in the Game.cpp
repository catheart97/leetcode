#include <vector>
#include <algorithm>
#include <iostream>

class Solution
{
public:
    int numberOfWeakCharacters(std::vector<std::vector<int>>& properties)
    {
        // partition
        std::sort( 
            properties.begin(), properties.end(), 
            [] (const auto & f, const auto & s) { return (f[0] == s[0]) ? f[1] > s[1] : f[0] < s[0]; }
        );

        int weak{0}, max{0};
        for (size_t i = 0; i < properties.size(); ++i)
        {
            const int VAL = properties[properties.size() - i - 1][1];
            if (VAL < max) ++weak;
            else max = VAL;
        }
        return weak;
    }
};


int main()
{
    std::vector<std::vector<int>> props{
        std::vector<int>{7, 9},
        std::vector<int>{10,7},
        std::vector<int>{6, 9},
        std::vector<int>{10,4},
        std::vector<int>{7, 5},
        std::vector<int>{7,10}
    };

    std::cout << Solution().numberOfWeakCharacters(props) << std::endl;

    return 0;
}