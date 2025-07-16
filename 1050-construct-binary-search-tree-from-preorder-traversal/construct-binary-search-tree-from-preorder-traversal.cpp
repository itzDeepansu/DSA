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
    TreeNode* makeTree(vector<int> preorder,pair<int,int> idx){
        if(idx.first>idx.second) return nullptr;
        TreeNode* root = new TreeNode(preorder[idx.first]);
        int part;
        for(int i = idx.first+1;i<=idx.second;i++){
            if(preorder[i]>preorder[idx.first]){
                part=i;
                break;
            }
        }
        root->left = makeTree(preorder,{idx.first+1,part-1});
        root->right = makeTree(preorder,{part,idx.second});
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return makeTree(preorder,{0,preorder.size()-1});
    }
};