class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> price(n+1,vector<int>(2,0));
        price[1][1]=nums[0];
        for(int i=2;i<=n;i++){
            price[i][0] = max(price[i-2][1],price[i-2][0]) + nums[i-1];
            price[i][1] = max(price[i-1][1],price[i-1][0]);
        }
        return max(price[n][0],price[n][1]);
    }
};
