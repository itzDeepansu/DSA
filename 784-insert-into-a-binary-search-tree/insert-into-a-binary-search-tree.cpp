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
    TreeNode* insertVal(TreeNode* node , int val){
        if(node==nullptr){
            return new TreeNode(val);
        }
        if(node->val > val){
            node->left = insertVal(node->left,val);
        }else{
            node->right = insertVal(node->right,val);
        }
        return node;
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        return insertVal(root,val);
    }
};