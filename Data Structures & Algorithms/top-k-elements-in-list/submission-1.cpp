class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> freq;
        set<pair<int,int>> st;
        for(auto it : nums)
        {
            freq[it]++;
            if(st.size()>0 && st.find({freq[it]-1,it}) != st.end())
            {
                st.erase(st.find({freq[it]-1,it}));
                st.insert({freq[it],it});
            }
            else if(st.size() < k)
                st.insert({freq[it],it});
            else if((*(st.begin())).first < freq[it])
            {
                st.erase(st.begin());
                st.insert({freq[it],it});
            }
        }
        vector<int> ans;
        for(auto it : st)
            ans.push_back(it.second);
        return ans;
    }
};
