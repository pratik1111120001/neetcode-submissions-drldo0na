class Solution {
public:
    void dfs(int i,int j,vector<vector<char>> &grid,vector<vector<int>> &vis)
    {
        int dx[4] = {0,0,-1,1};
        int dy[4] = {1,-1,0,0};
        int n = grid.size(), m = grid[0].size();
        for(int i1=0;i1<4;i1++)
        {
            int x = i + dx[i1];
            int y = j + dy[i1];
            if(x>=0 && x<n && y>=0 && y<m && grid[x][y] == '1' && vis[x][y] == 0){
                vis[x][y]=1;
                dfs(x,y,grid,vis);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == '1' && vis[i][j] == 0)
                {
                    cout<<endl;
                    vis[i][j]=1;
                    ans++;
                    dfs(i,j,grid,vis);
                }
            }
        }
        return ans;
    }
};
