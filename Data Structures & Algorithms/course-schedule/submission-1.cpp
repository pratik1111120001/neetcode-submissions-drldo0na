class Solution {
public:
    void dfs(int node,vector<int> &cnt, vector<vector<int>> &grid, int &curr){
        for(auto it : grid[node]){
            cnt[it]--;
            if(!cnt[it]){
                curr++;
                dfs(it,cnt,grid,curr);
            }
        }
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> cnt(numCourses,0);
        vector<vector<int>> grid(numCourses);
        for(auto it : prerequisites){
            grid[it[1]].push_back(it[0]);
            cnt[it[0]]++;
        }
        int curr = 0;
        vector<int> init;
        for(int i=0;i<numCourses;i++){
            if(!cnt[i]){
                init.push_back(i);
            }
        }
        for(auto it : init){
            curr++;
            dfs(it,cnt,grid,curr);
        }
        return (curr == numCourses);
    }
};
