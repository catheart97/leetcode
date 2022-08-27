class Solution
{
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k)
    {
        const auto m = matrix.size();
        const auto n = matrix[0].size();
        
        for (size_t i = 0; i < m; ++i)
            for (size_t j = 1; j < n; ++j)
                matrix[i][j] += matrix[i][j - 1];
        
        for (size_t i = 0; i < n; ++i)
            for (size_t j = 1; j < m; ++j)
                matrix[j][i] += matrix[j - 1][i];
        
        int maximum = INT_MIN;
        for (size_t i = 0; i < m; ++i)
        {
            for (size_t j = 0; j < n; ++j)
            {
                for (size_t ie = i; ie < m; ++ie)
                {
                    for (size_t je = j; je < n; ++je)
                    {
                        const int value = 
                            matrix[ie][je] 
                                - (     i ? matrix[i - 1][je]    : 0)
                                - (     j ? matrix[ie][j - 1]    : 0) 
                                + (i && j ? matrix[i - 1][j - 1] : 0);
                        
                        if (value < k && maximum < value)
                            maximum = value;
                        else if (value == k)
                            return k;
                    }
                }
            }
        }
        return maximum;
    }
};