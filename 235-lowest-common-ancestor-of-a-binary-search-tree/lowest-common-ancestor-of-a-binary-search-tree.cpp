/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* ancestor = nullptr;
    void traverse(TreeNode* node, TreeNode* p, TreeNode* q) {
        if (ancestor != nullptr)
            return;
        if (node == nullptr)
            return;
        if (p->val == node->val || q->val == node->val ||
            (p->val < node->val && q->val > node->val))
            ancestor = node;
        if (q->val < node->val)
            traverse(node->left, p, q);
        if (p->val > node->val)
            traverse(node->right, p, q);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p->val < q->val) {
            traverse(root, p, q);
        } else {
            traverse(root, q, p);
        }
        return ancestor;
    }
};