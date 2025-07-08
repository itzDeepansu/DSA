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
        if(node==nullptr) return 0;
        int ls = max(0,iterate(node->left,maxPathSum)); 
        int rs = max(0,iterate(node->right,maxPathSum));
        maxPathSum=max(maxPathSum,ls+rs+node->val); //checks downward bend
        maxPathSum=max(maxPathSum,node->val+max(ls,rs)); //checks upward bend
        return node->val+max(ls,rs); 
    }
    int maxPathSum(TreeNode* root) {
        int maxPathSum=INT_MIN;
        iterate(root,maxPathSum);
        return maxPathSum;
    }
};