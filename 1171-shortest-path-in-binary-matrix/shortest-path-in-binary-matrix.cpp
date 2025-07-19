class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0][0] == 1) return -1;
        
        int rows = grid.size();
        int cols = grid[0].size();  // fix here
        
        if (grid[0][0] == 1 || grid[rows - 1][cols - 1] == 1) return -1;
        
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        queue<pair<int, int>> q;
        q.push({0, 0});
        visited[0][0] = true;  // mark origin visited immediately
        
        int distance = 1;
        
        // 8 directions: all possible neighbors including diagonals
        vector<pair<int,int>> directions = {
            {1, 0}, {1, 1}, {0, 1}, {-1, 1},
            {-1, 0}, {-1, -1}, {0, -1}, {1, -1}
        };
        
        while (!q.empty()) {
            int sz = q.size();
            for (int itr = 0; itr < sz; itr++) {
                auto [i, j] = q.front();
                q.pop();
                
                if (i == rows - 1 && j == cols - 1)
                    return distance;
                
                for (auto& dir : directions) {
                    int ni = i + dir.first;
                    int nj = j + dir.second;
                    if (ni >= 0 && ni < rows && nj >= 0 && nj < cols &&
                        grid[ni][nj] == 0 && !visited[ni][nj]) {
                        visited[ni][nj] = true;
                        q.push({ni, nj});
                    }
                }
            }
            distance++;
        }
        
        return -1;
    }
};
