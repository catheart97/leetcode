class Solution
{
public:    
    void rotate(vector<vector<int>>& matrix)
    {            
        const auto N = matrix.size();
        
        for (size_t i = 0; i < N / 2; ++i)
        {
            for (size_t j = 0; j < (N + 1) / 2; ++j)
            {
                const size_t x1i{(N -   j - 1) % N}, x1j{  i};
                const size_t x2i{(N - x1j - 1) % N}, x2j{x1i};
                const size_t x3i{(N - x2j - 1) % N}, x3j{x2i};
                
                const int x0 = matrix[  i][  j];
                const int x1 = matrix[x1i][x1j];
                const int x2 = matrix[x2i][x2j];
                const int x3 = matrix[x3i][x3j];
                
                matrix[  i][  j] = x1;
                matrix[x1i][x1j] = x2;
                matrix[x2i][x2j] = x3;
                matrix[x3i][x3j] = x0;
            }
        }
    }
};