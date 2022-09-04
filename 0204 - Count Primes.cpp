#include <vector>
#include <iostream>
#include <cmath>
#include <unordered_set>

class Solution
{
public:
    constexpr bool isPrime(int n) const noexcept
    {
        for (size_t x = 2; x <= std::sqrt(n); ++x)
            if (n % x == 0) return false;
        return true;
    }

    int countPrimes(int n)
    {
        int c{0};
        std::vector<bool> eratosthenes(n - 2, false);
        for (size_t i = 2; i < n; ++i)
        {
            if (!eratosthenes[i - 2])
            {
                for (size_t j = i; j < n; j += i)
                    eratosthenes[j - 2] = true;
                c++;
            }
        }
        return c;
    }
};

int main()
{
    std::cout << Solution().countPrimes(1500000) << std::endl;
}