/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void iterate(TreeNode* node, TreeNode* newNode) {
        if (node->left != nullptr) {
            newNode->right = new TreeNode(node->left->val);
            iterate(node->left, newNode->right);
        }
        if (node->right != nullptr) {
            newNode->left = new TreeNode(node->right->val);
            iterate(node->right, newNode->left);
        }
        return;
    }
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr)
            return root;
        TreeNode* newRoot = new TreeNode(root->val);
        iterate(root, newRoot);
        return newRoot;
    }
};