class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        set<pair<double,int>> st;
        int n = points.size();
        for(int i=0;i<n;i++)
        {
            double curr_dis = (points[i][0]*points[i][0]*1.0) + (points[i][1]*points[i][1]*1.0);
            curr_dis = sqrt(curr_dis);
            st.insert({curr_dis,i});
            if(st.size() > k)
                st.erase(st.find(*(st.rbegin())));
        }
        vector<vector<int>> ans;
        for(auto it : st)
            ans.push_back(points[it.second]);
        
        return ans;
    }
};
