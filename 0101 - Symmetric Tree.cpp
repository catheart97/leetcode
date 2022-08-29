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
    bool isSymmetricH(TreeNode* l, TreeNode* r)
    {
        if (!l && !r) return true; // two empty trees are symmetrical
        if (!l || !r || l->val != r->val) return false;
        
        return isSymmetricH(l->left, r->right) && isSymmetricH(r->left, l->right);
    }
    
    bool isSymmetric(TreeNode* root)
    {
        return isSymmetricH(root->left, root->right);
    }
};