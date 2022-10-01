#include <string>
#include <vector>
#include <functional>
#include <iostream>

template <class value_t>
std::ostream &operator<<(std::ostream &os, const std::vector<value_t> &v)
{
    os << "[";
    if (v.size())
    {
        for (size_t i = 0; i < v.size() - 1; ++i)
            os << v[i] << ", ";
        os << v.back();
    }
    os << "]";
    return os;
}

class Solution
{
    int numDecodings(std::string_view & s)
    {
        std::vector<int32_t> dp(s.size(), -1);

        std::function<int32_t(size_t)> traverse = [&traverse, &dp, &s] (size_t n) {
            if (dp[n] != -1) return dp[n];

            if (n == 0) return int(s[n] != '0');

            const int8_t sn  = s[n    ] - '0';
            const int8_t sn1 = s[n - 1] - '0';

            if (!(sn || sn1)) return dp[n] = 0;

            int32_t np{0};
            if (sn) np += traverse(n - 1);

            const int32_t VAL = sn1 * 10 + sn - 1;
            if (9 <= VAL && VAL < 26) np += (n > 1) ? traverse(n - 2) : 1;

            return dp[n] = np;
        };

        return traverse(s.size() - 1);
    }

public:
    int numDecodings(std::string & s)
    {
        std::string_view sv(s);
        // sv = sv.substr(sv.find_first_not_of('0'));
        return numDecodings(sv);
    }
};

int main()
{
    std::string encoding = "11106";
    std::cout << Solution().numDecodings(encoding) << std::endl;
    return 0;
}