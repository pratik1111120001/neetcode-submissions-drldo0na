class Solution {
public:
    void solve(vector<vector<char>> &board, string word, int ind, bool &ok, vector<vector<int>> vis,int i1,int j1){
        if(ind == word.size()){
            ok = true;
            return;
        }
        int n = board.size();
        int m = board[0].size();
        int dx[] = {0,0,-1,1};
        int dy[] = {1,-1,0,0};
        for(int k=0;k<4;k++){
            int i = i1 + dx[k];
            int j = j1 + dy[k];
            if(i>=0 && i<n && j>=0 && j<m && !vis[i][j] && board[i][j] == word[ind]){
                vis[i][j]=1;
                solve(board,word,ind+1,ok,vis,i,j);
                vis[i][j]=0;
            }
        }
    }
    bool exist(vector<vector<char>>& board, string word) {
        bool ok = false;
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == word[0]){
                    vis[i][j]=1;
                    solve(board,word,1,ok,vis,i,j);
                    vis[i][j]=0;
                }
                if(ok) break;
            }
            if(ok) break;
        }
        return ok;
    }
};
