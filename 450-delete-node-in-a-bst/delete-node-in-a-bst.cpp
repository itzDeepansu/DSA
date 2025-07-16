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
    TreeNode* rightDitach(TreeNode* node,TreeNode* right){
        if(!node) return nullptr;
        node->right=rightDitach(node->right,right);
        if(node->right==nullptr) node->right=right;
        return node;
    }
    TreeNode* search(TreeNode* node,int key){
        if(!node) return nullptr;
        if(node->val==key){
            if(!node->left) return node->right;
            return rightDitach(node->left,node->right);
        }
        node->left=search(node->left,key);
        node->right=search(node->right,key);
        return node;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        return search(root,key);
    }
};