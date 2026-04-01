class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int, std::greater<int>> st;
        vector<int> ans;
        int j=0; 
        for(auto it : nums)
        {
            st.insert(it);
            if(st.size() > k) 
                st.erase(st.find(nums[j])),j++;
            if(st.size() == k)
                ans.push_back(*(st.begin()));
        }
        return ans;
    }
};
