class Solution {
public:
    void dfs(int node, vector<vector<int>> &adj, vector<int> &vis){
        for(auto it : adj[node]){
            if(!vis[it]){
                vis[it]=1;
                dfs(it,adj,vis);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> vis(n,0);
        int ans=0;
        vector<vector<int>> adj(n);
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                vis[i]=1;
                ans++;
                dfs(i,adj,vis);
            }
        }
        return ans;
    }
};
