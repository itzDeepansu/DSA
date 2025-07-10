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
    void sortVectorOfVectors(vector<vector<int>>& vec) {
        sort(vec.begin(), vec.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 if (a[0] != b[0])
                     return a[0] > b[0]; // Sort by first element
                 return a[1] < b[1];     // If equal, sort by second
             });
    }
    void iterate(TreeNode* node, int x, int y,
                 unordered_map<int, vector<vector<int>>>& yxElMap) {
        if (node == nullptr)
            return;
        yxElMap[x].push_back({y, node->val});
        iterate(node->left, x - 1, y - 1, yxElMap);
        iterate(node->right, x + 1, y - 1, yxElMap);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> answer;
        unordered_map<int, vector<vector<int>>> yxElMap;
        iterate(root, 0, 0, yxElMap);
        map<int, vector<vector<int>>> ordered(yxElMap.begin(), yxElMap.end());
        for (auto el : ordered) {
            sortVectorOfVectors(el.second);
            vector<int> temp;
            for (auto vvce : el.second) {
                temp.push_back(vvce[1]);
            }
            answer.push_back(temp);
        }
        return answer;
    }
};