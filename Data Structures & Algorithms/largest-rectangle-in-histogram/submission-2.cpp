class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> leftInd(n,-1);
        vector<int> rightInd(n,n);
        stack<int> st;
        st.push(-1);
        for(int i=0;i<n;i++)
        {
            while(st.top()!= -1 && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(st.size())
                leftInd[i] = st.top();
            st.push(i);
        }
        while(st.size()) st.pop();
        st.push(n);
        for(int i=n-1;i>=0;i--)
        {
            while(st.top()!= n && heights[st.top()] >= heights[i]){\
                st.pop();
            }
            if(st.size())
                rightInd[i] = st.top();
            st.push(i);
        }
        int ans=0;
        for(int i=0;i<n;i++)
            ans = max(ans, (rightInd[i] - leftInd[i] - 1)*heights[i]);
        return ans;
    }
};
