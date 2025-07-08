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
    int iterate(TreeNode* node,int& sum){
        if(node==nullptr) return 0;
        int leftSum = iterate(node->left,sum);
        int rightSum = iterate(node->right,sum);
        sum+=abs(leftSum-rightSum);
        return node->val+leftSum+rightSum;
    }    
    int findTilt(TreeNode* root) {
        int sum =0;
        iterate(root,sum);
        return sum;
    }
};