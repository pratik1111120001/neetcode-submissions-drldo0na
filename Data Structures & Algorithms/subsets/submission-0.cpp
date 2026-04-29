class Solution {
public:
    void solve(vector<int> &nums,int ind,vector<vector<int>> &ans,vector<int> curr){
        if(ind == nums.size()){
            ans.push_back(curr);
            return;
        }
        solve(nums,ind+1,ans,curr);
        curr.push_back(nums[ind]);
        solve(nums,ind+1,ans,curr);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        solve(nums,0,ans,curr);
        return ans;
    }
};
