class Solution
{
public:
    int hammingWeight(int n) 
    {
        int count{0};
        for (int i = 0; i < 32; ++i) count += bool(n & (1 << i));
        return count;
    }
    
    int hammingDistance(int x, int y)
    {
        return hammingWeight(x ^ y);
    }
};