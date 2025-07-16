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
    bool found =false;
    void dfs(TreeNode* node,vector<int>& search,int k){
        if(!node || found) return;
        for(auto el:search){
            if(el+node->val == k){
                found=true;
                return;
            }
        }
        search.push_back(node->val);
        dfs(node->left,search,k);
        dfs(node->right,search,k);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> search;
        dfs(root,search,k);
        return found;
    }
};