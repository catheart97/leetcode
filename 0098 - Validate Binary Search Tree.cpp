/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    bool isValidBSTH(const TreeNode* root, const long MIN, const long MAX)
    {
        if (!root) return true;
        
        if (!(root->val < MAX && MIN < root->val))
            return false;
        
        return isValidBSTH(root->left, MIN, root->val) && isValidBSTH(root->right, root->val, MAX);
    }
    
    bool isValidBST(TreeNode* root)
    {
        return isValidBSTH(
            root, 
            std::numeric_limits<long>::lowest(), 
            std::numeric_limits<long>::max()
        );
    }
};