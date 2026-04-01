class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        map<int,int> freq;
        set<vector<int>> ans;
        int n=nums.size();
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int curr = nums[i] + nums[j];
                curr*=-1;
                if(freq[curr])
                {
                    vector<int> cand;
                    cand.push_back(nums[i]);
                    cand.push_back(nums[j]);
                    cand.push_back(curr);
                    sort(cand.begin(),cand.end());
                    ans.insert(cand);
                }
            }
            freq[nums[i]]=1;
        }
        vector<vector<int>> res;
        for(auto it : ans) res.push_back(it);
        return res;
    }
};
