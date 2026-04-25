class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size(), m =grid[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 0) q.push({i,j});
            }
        }
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        while(q.size()){
            pair<int,int> curr = q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int x = curr.first + dx[i];
                int y = curr.second + dy[i];
                if(x>=0 && x<n && y>=0 && y<m && grid[x][y] == 2147483647){
                    grid[x][y] = grid[curr.first][curr.second] + 1;
                    q.push({x,y});
                }
            }
        };
    }
};
