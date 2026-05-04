class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto it : nums) sum+=it;
        if(sum%2)
            return false;
        sum/=2;
        vector<bool> dp(sum+1,false);
        dp[0]=true;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i=0;i<n;i++){
            for(int j=sum;j>=nums[i];j--){
                dp[j] = dp[j] || dp[j-nums[i]];
            }
        }
        return dp[sum];
    }
};
