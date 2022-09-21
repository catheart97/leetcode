#include <vector>

class Solution
{
public:
    std::vector<int> sumEvenAfterQueries(std::vector<int>& nums, std::vector<std::vector<int>>& queries)
    {
        std::vector<int> sums(queries.size());
        
        int32_t sum{0};
        for (auto n : nums) sum += !(n % 2) * n;
        
        for (size_t i = 0; i < queries.size(); ++i)
        {
            const auto & query = queries[i];
            const size_t IDX   = query[1];
            const int    QUE   = query[0];
            const int    VAL   = nums[IDX];
            
            nums[IDX] = VAL + QUE;
            
            const bool ODD_VAL = VAL % 2;
            const bool ODD_QUE = QUE % 2;
            const bool COND    = ODD_VAL == ODD_QUE;            
            
            sum += COND * (QUE + ODD_VAL * VAL) - !(COND + ODD_VAL) * VAL;
            
            sums[i] = sum;
        }
        
        return std::move(sums);
    }
};