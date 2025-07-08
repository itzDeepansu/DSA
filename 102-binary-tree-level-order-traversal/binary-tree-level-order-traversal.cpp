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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> vc;
        if(root==nullptr) return vc;
        queue<TreeNode* > nodes;
        nodes.push(root);
        while(!nodes.empty()){
            int sz = nodes.size();
            vector<int> temp;
            for(int i=0;i<sz;i++){
                if(nodes.front()->left!=nullptr) nodes.push(nodes.front()->left);
                if(nodes.front()->right!=nullptr) nodes.push(nodes.front()->right);
                temp.push_back(nodes.front()->val);
                nodes.pop();
            }
            vc.push_back(temp);
        }
        return vc;
    }
};