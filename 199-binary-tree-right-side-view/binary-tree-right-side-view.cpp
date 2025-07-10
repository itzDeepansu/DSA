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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> answer;
        if(root==nullptr) return answer;

        queue<TreeNode* > q;
        q.push(root);

        while(!q.empty()){
            int sz = q.size();
            int temp;
            for(int i=0;i<sz;i++){
                temp = q.front()->val;
                if(q.front()->left != nullptr ) q.push(q.front()->left);
                if(q.front()->right != nullptr ) q.push(q.front()->right);
                q.pop();
            }
            answer.push_back(temp);
        }

        return answer;
    }
};