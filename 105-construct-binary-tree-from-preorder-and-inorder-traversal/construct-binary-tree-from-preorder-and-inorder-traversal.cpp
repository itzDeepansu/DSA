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
    TreeNode* dfs(vector<int> preOrder, vector<int> inOrder,
                  pair<int, int> inIdx, pair<int, int> preIdx) {
        if (preIdx.first > preIdx.second)
            return nullptr;
        TreeNode* root = new TreeNode(preOrder[preIdx.first]);
        if (preIdx.first != preIdx.second) {
            int idx = findIdx(inOrder, preOrder[preIdx.first], inIdx);
            int leftSize = idx - inIdx.first;
            root->left = dfs(preOrder, inOrder, {inIdx.first, idx - 1},
                             {preIdx.first + 1, preIdx.first + leftSize});
            root->right = dfs(preOrder, inOrder, {idx + 1, inIdx.second},
                              {preIdx.first + leftSize + 1, preIdx.second});
        }
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return dfs(preorder, inorder, {0, inorder.size() - 1},
                   {0, preorder.size() - 1});
    }
};