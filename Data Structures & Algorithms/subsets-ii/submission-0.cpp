class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> curr;
        solve(nums,0,ans,curr);
        return ans;
    }
    void solve(vector<int> &nums,int ind,vector<vector<int>> &ans,vector<int> curr){
        ans.push_back(curr);
        for(int j=ind;j<nums.size();j++)
        {
            if(j>ind && nums[j] == nums[j-1]) 
                continue;
            curr.push_back(nums[j]);
            solve(nums,j+1,ans,curr);
            curr.pop_back();
        }
    }
};
