class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        set<int> st;
        for(auto it : nums){
            auto canbe = st.lower_bound(it);
            if(canbe == st.end())
                st.insert(it);
            else{
                st.erase(canbe);
                st.insert(it);
            }
        }
        return st.size();
    }
};
