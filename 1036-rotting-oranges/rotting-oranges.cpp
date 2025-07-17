class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int time=0;
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        int fresh=0;
        queue<pair<int,int>> q; 
        for(int i=0;i<grid.size();i++){{
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==1) fresh++;
                else if(grid[i][j]==2) q.push({i,j});
            }
        }}
        if(fresh==0) return 0;
        while(!q.empty() && fresh!=0){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                if(fresh==0) break;
                int rowIdx = q.front().first; 
                int colIdx = q.front().second; 
                q.pop();
                //up
                if(rowIdx>0 && !visited[rowIdx-1][colIdx]){
                    visited[rowIdx-1][colIdx]=true;
                    if(grid[rowIdx-1][colIdx]==1){
                        fresh--;
                        q.push({rowIdx-1,colIdx});
                    }
                } 
                //down
                if(rowIdx<rows-1 && !visited[rowIdx+1][colIdx]){
                    visited[rowIdx+1][colIdx]=true;
                    if(grid[rowIdx+1][colIdx]==1){
                        fresh--;
                        q.push({rowIdx+1,colIdx});
                    }
                } 
                //left
                if(colIdx>0 && !visited[rowIdx][colIdx-1]){
                    visited[rowIdx][colIdx-1]=true;
                    if(grid[rowIdx][colIdx-1]==1){
                        fresh--;
                        q.push({rowIdx,colIdx-1});
                    }
                } 
                //right
                 if(colIdx<cols-1 && !visited[rowIdx][colIdx+1]){
                    visited[rowIdx][colIdx+1]=true;
                    if(grid[rowIdx][colIdx+1]==1){
                        fresh--;
                        q.push({rowIdx,colIdx+1});
                    }
                } 
            }
            time++;
        }
        return fresh==0 ? time : -1;
    }
};