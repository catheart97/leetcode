class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        for (int i = 0; i < 16; ++i)
        {
            uint32_t lbit { (1 << (31 - i)) & n };
            uint32_t rbit { (1 <<       i ) & n };
            
            if (!(bool(lbit) ^ bool(rbit))) continue;
            
            if (lbit)
            {
                n = n & ~(1 << (31 - i)); // clear left bit
                n = n |  (1 <<       i ); // set right bit
            }
            else
            {
                n = n |  (1 << (31 - i));
                n = n & ~(1 <<       i ); 
            } 
        }
        return n;
    }
};