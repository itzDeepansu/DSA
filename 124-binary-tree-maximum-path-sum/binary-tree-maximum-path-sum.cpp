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
    int iterate(TreeNode* node,int& maxPathSum){
        if(node->left==nullptr && node->right==nullptr){
            maxPathSum=max(maxPathSum,node->val);
            return node->val;
        }
        int ls=0;
        int rs=0;
        if(node->left!=nullptr) ls = iterate(node->left,maxPathSum); 
        if(node->right!=nullptr) rs = iterate(node->right,maxPathSum);
        ls=max(0,ls);
        rs=max(0,rs);
        maxPathSum=max(maxPathSum,ls+rs+node->val);
        maxPathSum=max(maxPathSum,node->val+max(ls,rs));
        return node->val+max(ls,rs); 
    }
    int maxPathSum(TreeNode* root) {
        int maxPathSum=INT_MIN;
        iterate(root,maxPathSum);
        return maxPathSum;
    }
};