class Solution {
public:
    void dfs(int i,int j,vector<vector<int>> &grid,vector<vector<int>> &vis,int &curr){
        curr++;
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        int n=grid.size(),m=grid[0].size();
        for(int i1=0;i1<4;i1++){
            int x = i + dx[i1];
            int y = j + dy[i1];
            if(x>=0 && x<n && y>=0 && y<m && vis[x][y] == 0 && grid[x][y] == 1){
                vis[x][y]=1;
                dfs(x,y,grid,vis,curr);
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(),m = grid[0].size();
        int ans=0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1 && vis[i][j] == 0){
                    int curr=0;
                    vis[i][j] = 1;
                    dfs(i,j,grid,vis,curr);
                    ans=max(ans,curr);
                }
            }
        }
        return ans;
    }
};
