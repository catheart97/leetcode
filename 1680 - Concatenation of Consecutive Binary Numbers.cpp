#include <iostream>
#include <bitset>
#include <cmath>

constexpr int MOD = int(1e9 + 7);

class Solution
{    
    inline int ffs(const int n)
    {
#if defined(__clang__) || defined(__GNUC__)
        return 32 - __builtin_clz(n);
#else
        return int(std::floorf(std::log2f(n))) + 1;
#endif
    }
    
public:
    int concatenatedBinary(int n)
    {
        long res = 1;

        for (int i = 2; i <= n; ++i)
        {
            res = res << ffs(i);

            std::cout << std::bitset<32>(res) << " " << i << std::endl;

            res += i;
            res %= MOD;
        }

        return res;
    }
};
int main()
{
    for (int i = 12; i < 13; ++i)
    {
        int sol = Solution().concatenatedBinary(i);
        std::cout << std::bitset<32>(sol) << " " << sol << std::endl;
    }

    return 0;
}