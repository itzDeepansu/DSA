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
    void inOrder(vector<int>& answer,TreeNode* node){
        if(node == nullptr) return;
        inOrder(answer,node->left);
        answer.push_back(node->val);
        inOrder(answer,node->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> answer;
        inOrder(answer,root);
        return answer;
    }
};