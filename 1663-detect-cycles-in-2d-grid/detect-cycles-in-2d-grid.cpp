class Solution {
public:
    bool checkDuplicates(vector<pair<int, int>> level) {
        for (int i = 0; i < level.size(); i++) {
            for (int j = i + 1; j < level.size(); j++) {
                if (level[i].first == level[j].first &&
                    level[i].second == level[j].second)
                    return true;
            }
        }
        return false;

        
    }
    bool checkCycle(const vector<vector<char>>& grid, char ch,
                    vector<vector<bool>>& visited, pair<int, int> currIdx) {
        auto [row, col] = currIdx;
        queue<pair<int, int>> q;
        q.push({row, col});
        visited[row][col] = true;
        vector<pair<int, int>> level;
        while (!q.empty()) {
            int sz = q.size();
            for (int itr = 0; itr < sz; itr++) {
                auto [i, j] = q.front();
                visited[i][j] = true;
                if (i > 0 && grid[i - 1][j] == ch && !visited[i - 1][j]) {
                    q.push({i - 1, j});
                    level.push_back({i - 1, j});
                }
                if (i < grid.size() - 1 && grid[i + 1][j] == ch &&
                    !visited[i + 1][j]) {
                    q.push({i + 1, j});
                    level.push_back({i + 1, j});
                }
                if (j > 0 && grid[i][j - 1] == ch && !visited[i][j - 1]) {
                    q.push({i, j - 1});
                    level.push_back({i, j - 1});
                }
                if (j < grid[0].size() - 1 && grid[i][j + 1] == ch &&
                    !visited[i][j + 1]) {
                    q.push({i, j + 1});
                    level.push_back({i, j + 1});
                }
                q.pop();
            }
            if (checkDuplicates(level))
                return true;
            level.clear();
        }
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        vector<vector<bool>> visited(grid.size(),
                                     vector<bool>(grid[0].size(), false));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (!visited[i][j] &&
                    checkCycle(grid, grid[i][j], visited, {i, j})) {
                    return true;
                }
            }
        }
        return false;
    }
};