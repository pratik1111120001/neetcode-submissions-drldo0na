class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> leftInd(n,0);
        vector<int> rightInd(n,0);
        stack<int> st;
        st.push(-1);
        for(int i=0;i<n;i++)
        {
            stack<int> curr;
            while(st.top()!= -1 && heights[st.top()] >= heights[i]){
                curr.push(st.top());
                st.pop();
            }
            leftInd[i] = st.top();
            while(curr.size()){
                st.push(curr.top());
                curr.pop();
            }
            st.push(i);
        }
        while(st.size()) st.pop();
        st.push(n);
        for(int i=n-1;i>=0;i--)
        {
            stack<int> curr;
            while(st.top()!= n && heights[st.top()] >= heights[i]){
                curr.push(st.top());
                st.pop();
            }
            rightInd[i] = st.top();
            while(curr.size()){
                st.push(curr.top());
                curr.pop();
            }
            st.push(i);
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            cout<<leftInd[i]<<" "<<rightInd[i]<<" "<<heights[i]<<endl;
            ans = max(ans, (rightInd[i] - leftInd[i] - 1)*heights[i]);
        }
        return ans;
    }
};
