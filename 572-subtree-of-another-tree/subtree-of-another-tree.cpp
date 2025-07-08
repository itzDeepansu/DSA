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
    void checkSubtree(TreeNode* p ,TreeNode* q, bool& check){
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
        checkSubtree(p->left,q->left,check);
        checkSubtree(p->right,q->right,check);
    }
    void iterate(TreeNode* p, TreeNode* q,bool& flag){
        if(flag) return;
        if(p==nullptr) return;
        if(p->val == q->val){
            bool check =true;
            checkSubtree(p,q,check);
            if(check) flag=true;
        }
        iterate(p->left,q,flag);
        iterate(p->right,q,flag);
    } 
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        bool flag =false;
        iterate(root,subRoot,flag);
        return flag;
    }
};