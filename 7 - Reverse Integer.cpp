class Solution
{    
public:
    int reverse(int x)
    {
        if (x == 1 << 31) return 0;
        
        if (x < 0) return -reverse(-x);
             
        int xrev{0}, t{x};
        while (t)
        {
            const int ndigit = t % 10;
            if (xrev > (2147483647 - ndigit) / 10)
                return 0;
            xrev = xrev * 10 + ndigit;
            t = t / 10; 
        }
        return xrev;
    }
};