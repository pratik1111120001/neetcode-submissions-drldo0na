class Solution {
public:
    void solve(vector<int> &nums,int ind,set<multiset<int>> &ans,multiset<int> curr,int tot,int target){
        if(tot == target){
            ans.insert(curr);
            return;
        }
        if(ind == nums.size() || tot > target){
            return;
        }
        solve(nums,ind+1,ans,curr,tot,target);
        curr.insert(nums[ind]);
        solve(nums,ind,ans,curr,tot+nums[ind],target);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        set<multiset<int>> ans;
        multiset<int> curr;
        solve(nums,0,ans,curr,0,target);
        vector<vector<int>> res;
        for(auto x : ans){
            vector<int> canbe;
            for(auto it : x){
                canbe.push_back(it);
            }
            res.push_back(canbe);
        }
        return res;
    }
};
