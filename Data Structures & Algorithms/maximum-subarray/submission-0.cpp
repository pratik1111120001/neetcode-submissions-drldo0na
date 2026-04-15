class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=INT_MIN,curr=0;
        for(auto it : nums)
        {
            curr+=it;
            ans=max(ans,curr);
            curr = max(curr,0);
        }
        return ans;
    }
};
