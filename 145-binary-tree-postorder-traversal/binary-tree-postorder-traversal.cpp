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
    void postOrder(vector<int>& answer,TreeNode* node){
        if(node == nullptr) return;
        postOrder(answer,node->left);
        postOrder(answer,node->right);
        answer.push_back(node->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> answer;
        postOrder(answer,root);
        return answer;
    }
};