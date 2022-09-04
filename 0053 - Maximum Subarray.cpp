#include <iostream>
#include <vector>

class Solution
{
public:
    int maxSubArray(std::vector<int> & nums)
    {
        int max = std::numeric_limits<int>::lowest(), psum{0};
        for (size_t i = 0; i < nums.size(); ++i)
        {
            psum = (psum > 0)   ? psum + nums[i] : nums[i];
            max  = (psum > max) ? psum           : max    ;
        }
                
        return max;
    }
};

int main()
{
    std::vector<int> data {-1, -2, -1, 5, -1, 1, 4};
    std::cout << Solution().maxSubArray(data) << std::endl;
    return 0; 
}