class Solution {
public:
    bool isBorder(const vector<vector<char>>& board,
                  vector<pair<int, int>>& idxs, pair<int, int> currIdx, vector<vector<bool>>& visited) {
        auto [i, j] = currIdx;
        if (board[i][j] == 'X' || visited[i][j]) return false;
        visited[i][j] = true;
        if (i == 0 || j == 0 || i == board.size() - 1 ||
            j == board[i].size() - 1) return true;
        idxs.push_back({i,j});
        bool top = isBorder(board, idxs, {i - 1, j},visited);
        bool bottom = isBorder(board, idxs, {i + 1, j},visited);
        bool left = isBorder(board, idxs, {i, j - 1},visited);
        bool right = isBorder(board, idxs, {i, j + 1},visited);
        return (top || bottom || left || right);
    }
    void solve(vector<vector<char>>& board) {
        vector<pair<int,int>> idxs;
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        for(int i=1;i<board.size()-1;i++){
            for(int j=1;j<board[i].size()-1;j++){
                if(board[i][j]=='O' && !visited[i][j]){
                    if(isBorder(board,idxs,{i,j},visited)) idxs.clear();
                    else{
                        for(auto idx : idxs) board[idx.first][idx.second]='X';
                        idxs.clear();
                    }
                }
            }
        }
    }
};