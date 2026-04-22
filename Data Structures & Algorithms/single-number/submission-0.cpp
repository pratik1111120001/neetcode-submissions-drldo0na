class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int curr=0;
        for(auto it : nums) curr^=it;
        return curr;
    }
};
