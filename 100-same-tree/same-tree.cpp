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
    void iterate(TreeNode* p ,TreeNode* q, bool& check){
        if(!check) return;
        if((p==nullptr && q!=nullptr) || (p!=nullptr && q==nullptr)){
            check=false;
            return;
        }
        if(p==nullptr && q==nullptr) return;
        if(p->val!=q->val){
            check=false;
            return;
        }
        iterate(p->left,q->left,check);
        iterate(p->right,q->right,check);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool check=true;
        iterate(p,q,check);
        return check;
    }
};