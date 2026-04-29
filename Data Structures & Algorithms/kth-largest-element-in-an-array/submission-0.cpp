class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        multiset<int> st;
        for(auto it : nums)
        {
            st.insert(-1*it);
            if(st.size() > k)
                st.erase(st.find(*(st.rbegin())));
        }
        int ans = *(st.rbegin());
        return -1*ans;
    }
};
