class Solution
{
public:
    bool isValidBlock(
        const std::vector<std::vector<char>>& board, 
        std::array<bool, 9> & blk_valid,
        size_t bi,
        size_t bj
    )
    {
        if (blk_valid[bi * 3 + bj]) return true;
        
        std::array<bool, 9> found{};
        for (size_t i = bi * 3; i < bi * 3 + 3; ++i)
        {
            for (size_t j = bj * 3; j < bj * 3 + 3; ++j)
            {
                auto value = board[i][j];
                if (value == '.')
                    continue;
                
                int number = value - '0' - 1;
                if (found[number]) return false;
                found[number] = true;    
            }
        }
        
        return blk_valid[bi * 3 + bj] = true;
    }
    
    bool isValidRow(
        const std::vector<std::vector<char>>& board, 
        std::array<bool, 9> & row_valid,
        size_t i
    )
    {
        if (row_valid[i]) return true;
        
        std::array<bool, 9> found{};
        for (size_t j = 0; j < 9; ++j)
        {
            auto value = board[i][j];
            if (value == '.')
                continue;

            int number = value - '0' - 1;
            if (found[number]) return false;
            found[number] = true;    
        }
        
        return row_valid[i] = true;
    }
    
    bool isValidCol(
        const std::vector<std::vector<char>>& board, 
        std::array<bool, 9> & col_valid,
        size_t j
    )
    {
        if (col_valid[j]) return true;
        
        std::array<bool, 9> found{};
        for (size_t i = 0; i < 9; ++i)
        {
            auto value = board[i][j];
            if (value == '.')
                continue;

            int number = value - '0' - 1;
            if (found[number]) return false;
            found[number] = true;    
        }
        
        col_valid[j] = true;
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board)
    {
        std::array<bool, 9> blk_valid{};
        std::array<bool, 9> row_valid{};
        std::array<bool, 9> col_valid{};
        
        for (size_t i = 0; i < 9; ++i)
        {
            for (size_t j = 0; j < 9; ++j)
            {
                auto value = board[i][j];
                if (value == '.')
                    continue;
                
                size_t bi{i / 3}, bj{j / 3};
                
                if (!isValidBlock(board, blk_valid, bi, bj)) return false;
                
                if (!isValidRow(board, row_valid, i)) return false;
                
                if (!isValidCol(board, col_valid, j)) return false;
            }
        }
        return true;
    }
};