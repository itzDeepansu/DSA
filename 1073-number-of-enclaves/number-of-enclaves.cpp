class Solution {
public:
    bool isBorder(const vector<vector<int>>& board,int &count, pair<int, int> currIdx, vector<vector<bool>>& visited) {
        auto [i, j] = currIdx;
        if (board[i][j] == 0 || visited[i][j]) return false;
        visited[i][j] = true;
        if (i == 0 || j == 0 || i == board.size() - 1 ||
            j == board[i].size() - 1){
                return true;
        }
        count++;
        bool top = isBorder(board, count, {i - 1, j},visited);
        bool bottom = isBorder(board, count, {i + 1, j},visited);
        bool left = isBorder(board, count, {i, j - 1},visited);
        bool right = isBorder(board, count, {i, j + 1},visited);
        return (top || bottom || left || right);
    }
    int numEnclaves(vector<vector<int>>& board) {
        int answer=0;
        int count=0;
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        for(int i=1;i<board.size()-1;i++){
            for(int j=1;j<board[i].size()-1;j++){
                if(board[i][j]==1 && !visited[i][j]){
                    if(isBorder(board,count,{i,j},visited)){
                        count=0;
                    }
                    else{
                        answer+=count;
                        count=0;
                    }
                }
            }
        }
        return answer;
    }
};