#include <iostream>
#include <bitset>

class Solution
{
public:
    int hammingWeight(uint32_t n) 
    {
        int count{0};
        for (int i = 0; i < 32; ++i) count += bool(n & (1 << i));
        return count;
    }
};