#include <vector>

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

using vecvec = std::vector<std::vector<int>>;

class Solution
{
public:
    vecvec pathSumH(TreeNode *root, int target_sum, int depth)
    {   
        if (!root) return {};

        target_sum -= root->val;
        
        if (!root->left && !root->right) // leaf
        {
            if (target_sum) return {};
            else 
            {
                vecvec res(1);
                res[0].reserve(depth);
                res[0].push_back(root->val);
                return std::move(res);
            }
        }

        vecvec left = pathSumH(root->left, target_sum, depth + 1);
        if (left.size())
            for (auto & vec : left) vec.push_back(root->val);

        vecvec right = pathSumH(root->right, target_sum, depth + 1);
        if (right.size())
            for (auto & vec : right) vec.push_back(root->val);

        if (!left.size() && right.size()) std::swap(left, right);

        left.reserve(left.size() + right.size());
        for (auto & vec : right) left.push_back(vec);

        return std::move(left);
    }

    vecvec pathSum(TreeNode *root, int target_sum)
    {
        vecvec res = pathSumH(root, target_sum, 1);

        for (auto & vec : res)
            std::reverse(vec.begin(), vec.end());

        return std::move(res);
    }
};