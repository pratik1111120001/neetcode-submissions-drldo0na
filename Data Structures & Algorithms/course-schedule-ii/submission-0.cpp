class Solution {
public:
    void dfs(int node,vector<int> &cnt, vector<vector<int>> &grid, vector<int> &curr){
        for(auto it : grid[node]){
            cnt[it]--;
            if(!cnt[it]){
                curr.push_back(it);
                dfs(it,cnt,grid,curr);
            }
        }
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> cnt(numCourses,0);
        vector<vector<int>> grid(numCourses);
        for(auto it : prerequisites){
            grid[it[1]].push_back(it[0]);
            cnt[it[0]]++;
        }
        vector<int> curr;
        vector<int> init;
        for(int i=0;i<numCourses;i++){
            if(!cnt[i]){
                init.push_back(i);
            }
        }
        for(auto it : init){
            curr.push_back(it);
            dfs(it,cnt,grid,curr);
        }
        if(curr.size() != numCourses)
            curr.clear();
        return curr;
    }
};
