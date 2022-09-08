#include <vector>
#include <stack>
#include <memory>
#include <iostream>
#include <unordered_set>

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

// iterative solution

// class Solution
// {
// public:
//     std::vector<int> inorderTraversal(TreeNode *root)
//     {
//         std::vector<int> result;
//         if (!root) return std::move(result);

//         std::stack<TreeNode *> nodes{};
//         std::unordered_set<TreeNode *> visited;
//         nodes.push(root);
        
//         while (!nodes.empty())
//         {
//             auto node = nodes.top();
            
//             if (node->left && visited.find(node->left) == visited.end())
//             {
//                 nodes.push(node->left);
//                 continue;
//             }
            
//             nodes.pop();
            
//             result.push_back(node->val);
//             if (node->right) nodes.push(node->right);
//             visited.insert(node);
//         }

//         return std::move(result);
//     }
// };


// recursive solution (obviously faster)
class Solution
{
    void traverse(TreeNode * node, std::vector<int> & result)
    {
        if (!node) return;
        
        traverse(node->left, result);
        result.push_back(node->val);
        traverse(node->right, result);
    }
    
public:
    std::vector<int> inorderTraversal(TreeNode *root)
    {
        std::vector<int> result;
        traverse(root, result);
        return std::move(result);
    }
};