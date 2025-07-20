class Solution {
public:
    int ans = INT_MAX;
    int n, m;
    vector<vector<int>> memo;
    void dfs(const vector<vector<int>>& heights, vector<vector<bool>>& visited, int x, int y, int localDiff) {
        if (x == n-1 && y == m-1) {
            ans = min(ans, localDiff);
            return;
        }
        static vector<pair<int,int>> directions = {{0,1},{0,-1},{1,0},{-1,0}};
        for (auto& [dx, dy] : directions) {
            int nx = x+dx, ny = y+dy;
            if (nx<0 || nx>=n || ny<0 || ny>=m || visited[nx][ny]) continue;
            int nextEffort = max(localDiff, abs(heights[x][y]-heights[nx][ny]));
            if (nextEffort >= ans) continue;
            if (nextEffort >= memo[nx][ny]) continue;
            memo[nx][ny] = nextEffort;
            visited[nx][ny] = true;
            dfs(heights, visited, nx, ny, nextEffort);
            visited[nx][ny] = false;
        }
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        n = heights.size();
        m = heights[0].size();
        memo = vector<vector<int>>(n, vector<int>(m, INT_MAX));
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        visited[0][0] = true;
        memo[0][0] = 0;
        dfs(heights, visited, 0, 0, 0);
        return ans;
    }
};
