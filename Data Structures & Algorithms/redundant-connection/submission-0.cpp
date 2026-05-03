class Solution {
public:
    int findPar(vector<int> &par,int n){
        if(par[n] == n) 
            return n;
        return par[n] = findPar(par,par[n]);
    }
    void unionSet(int u, int v, vector<int> &sz, vector<int> &par){
        if(sz[u] > sz[v])
            swap(u,v);
        par[u] = v;
        sz[v] += sz[u]; 
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> par(n+1,0),sz(n+1,1);
        for(int i=1;i<=n;i++) par[i]=i;
        vector<int> ans(2,0);
        for(auto it : edges){
            int x = findPar(par,it[0]);
            int y = findPar(par,it[1]);
            if(x==y){
                ans[0]=it[0];
                ans[1]=it[1];
            }
            else{
                unionSet(x,y,sz,par);
            }
        }
        return ans;
    }
};
