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
    void sym(TreeNode* leftNode, TreeNode* rightNode, bool& flag) {
        if (!flag)
            return;
        if(leftNode==nullptr && rightNode==nullptr ) return;
        if ((leftNode == nullptr && rightNode != nullptr) ||
            (leftNode != nullptr && rightNode == nullptr)) {
            flag = false;
            return;
        }
        if(leftNode->val == rightNode->val){
            sym(leftNode->left,rightNode->right,flag);
            sym(leftNode->right,rightNode->left,flag);
        }else{
            flag=false;
        }
    }
    bool isSymmetric(TreeNode* root) {
        bool flag =true;
        if(root->left==nullptr && root->right == nullptr) return true;
        cout<<"here";
        sym(root->left,root->right,flag);
        return flag;
    }
};