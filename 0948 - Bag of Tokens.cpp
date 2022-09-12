#include <vector>

class Solution
{
public:
    int bagOfTokensScore(std::vector<int> & tokens, int power)
    {
        if (!tokens.size()) return 0;
        
        std::sort(tokens.begin(), tokens.end());
        
        int score {0};
        size_t i {0}, j {tokens.size() - 1};
        while (i <= j)
        {
            if (tokens[i] <= power)       // face up
            {
                power -= tokens[i++];
                score++;
            }
            else if (i + 1 < j && score)  // face down
            {
                power += tokens[j--];
                score--;
            }   
            else 
            {
                break;
            }
        }
        
        return score;
    }
};