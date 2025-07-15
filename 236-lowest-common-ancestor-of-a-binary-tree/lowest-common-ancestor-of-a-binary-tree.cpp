/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lca;
    int dfs(TreeNode* node, TreeNode* p, TreeNode* q) {
        if(!node) return 0;
        int left = dfs(node->left,p,q);
        int right = dfs(node->right,p,q);
        if(node==p || node==q){
            if((left || right) && !lca) lca=node;
            return left+right+1;
        }else{
            if(left+right==2 && !lca ) lca=node;
            return left+right;
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root,p,q);
        return lca;
    }
};