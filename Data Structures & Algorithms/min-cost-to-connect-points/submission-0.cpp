class Solution {
public:
    int findPar(int n, vector<int> &par){
        if(n == par[n]) return n;
        return par[n] = findPar(par[n],par);
    }
    void setUnion(int u, int v, vector<int> &par, vector<int> &sz){
        if(sz[u] > sz[v])
            swap(u,v);
        par[u]=v;
        sz[v]+=sz[u];
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<pair<int,pair<int,int>>> adj;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int dis = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
                adj.push_back({dis,{i,j}});
            }
        }
        sort(adj.begin(),adj.end());
        int ans=0;
        vector<int> par(n),sz(n,0);
        for(int i=0;i<n;i++) par[i]=i;
        for(auto it : adj){
            int dis = it.first;
            int u = it.second.first;
            int v = it.second.second;
            u = findPar(u,par);
            v = findPar(v,par);
            if(u != v){
                ans+=dis;
                setUnion(u,v,par,sz);
            }
        }
        return ans;
    }
};
