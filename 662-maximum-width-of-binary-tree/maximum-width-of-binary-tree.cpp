class Solution {
public:
    void dfs(TreeNode* node, int level, unsigned long long index,
             unordered_map<int, pair<unsigned long long, unsigned long long>>& levelMap) {
        if (!node)
            return;
        if (levelMap.find(level) == levelMap.end()) {
            levelMap[level] = {index, index};
        } else {
            levelMap[level].second = index;
        }
        dfs(node->left, level + 1, (2ULL * index) + 1, levelMap);
        dfs(node->right, level + 1, (2ULL * index) + 2, levelMap);
    }

    int widthOfBinaryTree(TreeNode* root) {
        unsigned long long ans = 1;
        unordered_map<int, pair<unsigned long long, unsigned long long>> levelMap;
        dfs(root, 0, 0, levelMap);
        for (auto el : levelMap) {
            ans = max(ans, el.second.second - el.second.first + 1);
        }
        return static_cast<int>(ans);
    }
};
