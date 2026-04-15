class Solution {
public:
    bool canJump(vector<int>& nums) {
        int curr=0,n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(curr<i) break;
            curr=max(curr,i+nums[i]);
        }
        return (curr>=n-1);
    }
};
