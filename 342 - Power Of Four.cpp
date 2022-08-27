class Solution
{
public:
    bool isPowerOfFour(const int n)
    {
        if (n > 0)
        {
            constexpr int32_t mask = 0b01010101010101010101010101010101;
            return ((n & mask) == n) && !(n & (n - 1));
        }
        return false;
    }
};