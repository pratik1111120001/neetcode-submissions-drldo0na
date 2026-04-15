class Solution {
public:
    int jump(vector<int>& nums) {
        int curr=0,ans=0,maxi=0,n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(curr >= n-1) break;
            maxi=max(maxi,i+nums[i]);
            if(i == curr) curr=maxi,ans++;
        }
        return ans;
    }
};
