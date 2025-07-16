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
class Solution {
public:
    void inOrder(TreeNode* node,vector<int>& vc){
        if(!node) return;
        inOrder(node->left,vc);
        vc.push_back(node->val);
        inOrder(node->right,vc);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> vc;
        inOrder(root,vc);
        return vc[k-1];
    }
};