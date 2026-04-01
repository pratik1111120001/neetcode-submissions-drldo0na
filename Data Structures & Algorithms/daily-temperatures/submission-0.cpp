class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> st;
        int n=temperatures.size();
        vector<int> ans(n);
        for(int i=n-1;i>=0;i--)
        {
            int curr_min=n;
            stack<pair<int,int>> temp;
            while(st.size() && st.top().first > temperatures[i])
            {
                curr_min=min(curr_min,st.top().second);
                temp.push(st.top());
                st.pop();
            }
            st.push({temperatures[i],i});
            while(temp.size())
            {
                st.push(temp.top());
                temp.pop();
            }
            if(curr_min == n) curr_min=i;
            ans[i] = (curr_min-i);
        }
        return ans;
    }
};
