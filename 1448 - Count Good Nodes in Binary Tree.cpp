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
private:
    void goodNodesH(TreeNode * node, int v, int & c)
    {
        if (!node) return;

        if (node->val >= v) 
        {
            c += 1;
            v = node->val;
        }

        goodNodesH(node->left, v, c);
        goodNodesH(node->right, v, c);
    }
    
public:
    int goodNodes(TreeNode* root)
    { 
        int c{0};
        goodNodesH(root, int(-10e4), c);
        return c;
    }
};