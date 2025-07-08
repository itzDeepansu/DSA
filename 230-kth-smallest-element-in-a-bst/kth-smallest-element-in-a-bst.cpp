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
    void fillPQ(TreeNode* node ,priority_queue<int, vector<int>, greater<int>>& minPQ){
        if(node==nullptr) return;
        minPQ.push(node->val);
        fillPQ(node->left,minPQ);
        fillPQ(node->right,minPQ);
    }
    int kthSmallest(TreeNode* root, int k) {
        priority_queue<int, vector<int>, greater<int>> minPQ;
        fillPQ(root,minPQ);
        k--;
        while(k){
            minPQ.pop();
            k--;
        }
        return minPQ.top();
    }
};