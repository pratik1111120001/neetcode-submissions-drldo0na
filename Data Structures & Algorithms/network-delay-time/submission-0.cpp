class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> time(n+1,INT_MAX);
        int ans=0;
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto it : times)
            adj[it[0]].push_back({it[1],it[2]});
        priority_queue<pair<int,int>> q;
        time[k]=0;
        q.push({0,k});
        while(q.size()){
            pair<int,int> curr = q.top();
            q.pop();
            for(auto it : adj[curr.second]){
                if(time[it.first] > curr.first + it.second){
                    time[it.first] = curr.first + it.second;
                    q.push({time[it.first],it.first});
                }
            }
        }
        for(int i=1;i<=n;i++){
            if(time[i] == INT_MAX){
                ans=-1;
                break;
            }
            ans=max(ans,time[i]);
        }
        return ans;
    }
};
