#include <vector>
#include <iostream>

class Solution
{
public:
    int numIslands(std::vector<std::vector<char>> &grid)
    {
        const size_t M{grid.size()}, N{grid[0].size()};
        std::vector<int> buffer0(N), buffer1(N);
        int num_islands = 0;

        for (size_t i = 0; i < M; ++i)
        {
            for (size_t j = 0; j < N; ++j)
            {
                if (((i < M && j < N) ? grid[i][j] - '0' : 0) == 0)  // water
                {
                    buffer1[j] = 0;
                    continue;
                }

                auto above {buffer0[j]};
                auto left  {(j > 0) ? buffer1[j - 1] : 0};

                if (above == 0 && left == 0)                         // new island
                {
                    buffer1[j] = ++num_islands;
                }
                else if (above == left || (left == 0 && above != 0)) // grow island
                {
                    buffer1[j] = above;
                }
                else if (above == 0 && left != 0)                    // grow island
                {
                    buffer1[j] = left;
                }
                else                                                 // join islands
                {
                    const auto mmin = std::min(above, left);
                    const auto mmax = std::max(above, left);
                    const auto cond = !(num_islands == mmax);
                    buffer1[j] = mmin;

                    for (size_t jj = 0; jj < N; ++jj)
                    {
                        auto entry = buffer0[jj];
                        if (entry == mmax) buffer0[jj] = mmin;
                        else if (cond && entry == num_islands) buffer0[jj] = mmax;
                    }
                    
                    for (size_t jj = 0; jj < j; ++jj)
                    {
                        auto entry = buffer1[jj];
                        if (entry == mmax) buffer1[jj] = mmin;
                        else if (cond && entry == num_islands) buffer1[jj] = mmax;
                    }
                    
                    num_islands--;
                }
            }
            
            std::swap(buffer0, buffer1);
        }
            

        return num_islands;
    }
};

int main()
{
    std::vector<std::vector<char>> grid = {
        std::vector<char>{'1', '1', '1', '1', '0'},
        std::vector<char>{'1', '1', '0', '1', '0'},
        std::vector<char>{'1', '1', '0', '0', '0'},
        std::vector<char>{'0', '0', '0', '0', '0'}};

    std::cout << Solution().numIslands(grid) << std::endl;

    grid = {
        std::vector<char>{'1', '1', '0', '0', '0'},
        std::vector<char>{'1', '1', '0', '0', '0'},
        std::vector<char>{'0', '0', '1', '0', '0'},
        std::vector<char>{'0', '0', '0', '1', '1'}};

    std::cout << Solution().numIslands(grid) << std::endl;

    return 0;
}