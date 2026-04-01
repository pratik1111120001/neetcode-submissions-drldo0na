class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,int> freq;
        int ans=0;
        for(auto it : nums)
        {
            int x=it;
            if(!freq[x])
            {
                freq[x] = freq[x-1] + 1;
                x++;
                while(freq[x]) freq[x] = freq[x-1] + 1,x++;
                ans=max(ans,freq[x-1]);
            }
        }
        return ans;
    }
};
