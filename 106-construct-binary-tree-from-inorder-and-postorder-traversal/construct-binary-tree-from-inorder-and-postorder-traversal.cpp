/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int findIdx(vector<int> inOrder, int val, pair<int, int> leng) {
        for (int i = leng.first; i <= leng.second; i++) {
            if (inOrder[i] == val)
                return i;
        }
        return 0;
    }
    TreeNode* dfs(vector<int> postOrder, vector<int> inOrder,
                  pair<int, int> inIdx, pair<int, int> postIdx) {
        if (postIdx.first > postIdx.second)
            return nullptr;
        TreeNode* root = new TreeNode(postOrder[postIdx.first]);
        if (postIdx.first != postIdx.second) {
            int idx = findIdx(inOrder, postOrder[postIdx.first], inIdx);
            int rightSize =  inIdx.second - idx;
            root->right = dfs(postOrder, inOrder, {idx + 1, inIdx.second},
                              {postIdx.first+1,postIdx.first + rightSize});
            root->left = dfs(postOrder, inOrder, {inIdx.first, idx - 1},
                             {postIdx.first + rightSize+1, postIdx.second});
        }
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        reverse(postorder.begin(), postorder.end());
        return dfs(postorder, inorder, {0, inorder.size() - 1},
                   {0, postorder.size() - 1});
    }
};