bool isOdd(int v) { return v % 2; }

class Solution
{
public:
    inline bool isPseudoPalindrome(const std::array<int, 10> & c, const bool ODD)
    {              
        if (ODD)
        {
            if (std::any_of(c.begin(), c.end(), isOdd))
                return std::count_if(c.begin(), c.end(), isOdd) == 1;
            return false;
        }
        else 
        {
            return std::none_of(c.begin(), c.end(), isOdd);
        }
    }
    
    int pseudoPalindromicPaths (const TreeNode* node, std::array<int, 10> & c, const bool ODD)
    {
        c[node->val] += 1;
        
        int result{0};
        if (!node->left && !node->right) // leaf
        {
            result = isPseudoPalindrome(c, ODD);
        }
        else 
        {
            if (node->left)  result += pseudoPalindromicPaths(node->left, c, !ODD);
            if (node->right) result += pseudoPalindromicPaths(node->right, c, !ODD);
        }
        
        c[node->val] -= 1;
        return result;
        
    }
    
    int pseudoPalindromicPaths (TreeNode* root)
    {
        std::array<int, 10> c{};
        return pseudoPalindromicPaths(root, c, true);
    }
};