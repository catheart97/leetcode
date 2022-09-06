
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution 
{
public:
    bool containsOne(TreeNode* root)
    {
        if (!root) return false;
        
        bool lres { containsOne(root->left) };
        if (!lres)
        {
            delete root->left;
            root->left = nullptr;
        }
        
        bool rres { containsOne(root->right) };
        if (!rres)
        {
            delete root->right;
            root->right = nullptr;
        }
        
        return root->val || lres || rres;
    }
    
    TreeNode* pruneTree(TreeNode* root)
    {
        if (!root) return nullptr;
        
        if (!containsOne(root))
        {
            delete root;
            return nullptr;
        }
        
        return root;
    }
};