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
    void iterate(TreeNode* node,vector<string>& answers,string str){
        str+="->";
        str+=to_string(node->val);
        if(node->left ==nullptr && node->right == nullptr){
            answers.push_back(str.substr(2));
            return;
        }
        if(node->left!=nullptr) iterate(node->left,answers,str);
        if(node->right!=nullptr) iterate(node->right,answers,str);
        return;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> answers;
        iterate(root,answers,"");
        return answers;
    }
};