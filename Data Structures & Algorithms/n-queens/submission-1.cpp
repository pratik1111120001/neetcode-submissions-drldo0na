class Solution {
public:
    void solve(vector<int> row,vector<int> col, vector<int> diag,vector<int> rdiag, vector<vector<string>> &ans, vector<string> curr, int i, int n){
        if(i == n){
            ans.push_back(curr);
            return;
        }        
        for(int j=0;j<n;j++){
            int x = i+j;
            int y = n+i-j;
            if(curr[i][j]=='.' && !row[i] && !col[j] && !diag[x] && !rdiag[y]){
                curr[i][j]='Q';
                row[i]=1;
                col[j]=1;
                diag[x]=1;
                rdiag[y]=1;

                solve(row,col,diag,rdiag,ans,curr,i+1,n);

                curr[i][j]='.';
                row[i]=0;
                col[j]=0;
                diag[x]=0;
                rdiag[y]=0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<int> row(n,0),col(n,0),diag(n*2,0),rdiag(n*2,0);
        vector<vector<string>> ans;
        string canbe="";
        for(int i=0;i<n;i++) canbe+='.';
        vector<string> curr(n,canbe);
        solve(row,col,diag,rdiag,ans,curr,0,n);
        return ans;
    }
};
