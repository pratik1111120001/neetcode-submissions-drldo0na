class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i=0,j=heights.size();
        j--;
        int ans=0;
        while(i<j)
        {
            int curr = min(heights[j], heights[i]) * (j-i);
            ans=max(ans,curr);
            if(heights[j] < heights[i]) j--;
            else i++;
        }
        return ans;
    }
};
