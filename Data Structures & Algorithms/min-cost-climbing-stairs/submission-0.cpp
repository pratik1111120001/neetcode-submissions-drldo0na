class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        cost.push_back(0);
        int n = cost.size();
        vector<int> ans(n,0);
        ans[0] = cost[0];
        ans[1] = cost[1];
        for(int i=2;i<n;i++) ans[i]=min(ans[i-1],ans[i-2]),ans[i]+=cost[i];
        return ans[n-1];
    }
};
