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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> answer;
        if(root==nullptr) return answer;
        bool flag=true;
        queue<TreeNode* > elems;
        elems.push(root);
        while(!elems.empty()){
            flag=!flag;
            int sz = elems.size();
            vector<int> temp(sz);
            for(int i=0;i<sz;i++){
                int idx = (!flag) ? i : (sz-1-i);
                temp[idx]=elems.front()->val;
                if(elems.front()->left !=nullptr) elems.push(elems.front()->left);
                if(elems.front()->right !=nullptr) elems.push(elems.front()->right);
                elems.pop();
            }
            answer.push_back(temp);
        }
        return answer;
    }
};