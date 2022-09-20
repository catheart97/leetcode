#include <vector>
#include <functional>
#include <iostream>
#include <tuple>
#include <bitset>
#include <cmath>

template<class value_t>
std::ostream & operator<<(std::ostream & os, const std::vector<value_t> & v)
{
    os << "[";
    if (v.size())
    {
        for (size_t i = 0; i < v.size() - 1; ++i) os << v[i] << ", ";
        os << v.back();
    }
    os << "]";
    return os;
}

class Solution
{
public:
    int findLength(std::vector<int>& nums1, std::vector<int>& nums2)
    {
        int32_t max {0};

        const size_t M = nums1.size(), N = nums2.size();
        std::vector<int32_t> dp(N * M, INT_MIN);

        std::function<int32_t(size_t, size_t)> traverse = 
            [&, N, M] (const size_t i, const size_t j)
        {
            if (i > M - 1 || j > N - 1) return 0;
           
            const size_t MIDX{i * N + j};
            if (dp[MIDX] != INT_MIN) return dp[MIDX];

            int32_t ans { (i + 1 < M && j + 1 < N) ? traverse(i + 1, j + 1) : 0 };

            if (nums1[i] == nums2[j])
            {
                ans = (ans > 0) * ans + 1;
                if (ans > max) max = ans;
            }
            else 
            {
                ans = (ans > 0) ? -ans : ans;
            }

            // compute solution boundaries
            if (max < std::min(M - i, N - j + 1)) traverse(i + 1, j);
            if (max < std::min(M - i + 1, N - j)) traverse(i, j + 1);

            return dp[MIDX] = ans;
        };

        traverse(0, 0);

        return max;
    }
};

int main()
{
    std::vector<int> nums1, nums2;

    nums1 = { 1, 2, 3, 2, 1 };
    nums2 = { 3, 2, 1, 4, 7 };
    std::cout << Solution().findLength(nums1, nums2) << std::endl;

    return 0;
}