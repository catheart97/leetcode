#include <vector>
#include <iostream>
#include <functional>

class Solution
{
public:
    int maximumScore(const std::vector<int> & nums, const std::vector<int> & multipliers) const
    {
        const size_t N{nums.size()};
        const size_t M{multipliers.size()};
        
        std::vector<int> dp((M + 1) * (M + 1), INT_MIN);
        
        std::function<int(int, int)> traverse = [N, M, &nums, &multipliers, &dp, &traverse] ( 
            const size_t i, 
            const size_t j
        ) {
            if (i + j == M) return 0; // recursion anchor

            int & dpv = dp[ i * (M + 1) + j]; // dp exit
            if (dpv != INT_MIN) return dpv;

            const int l = traverse(i + 1, j) + multipliers[i + j] * nums[i];
            const int r = traverse(i, j + 1) + multipliers[i + j] * nums[N - j - 1];

            return dpv = std::max(l, r);
        };
        
        return traverse(0, 0);
    }
};


int main()
{
    std::vector<int> nums {-5,-3,-3,-2,7,1}, multipliers {-10,-5,3,4,6};

    std::cout << Solution().maximumScore(nums, multipliers) << std::endl;

    return 0;
}