class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0,repeat=0,n=s.size();
        map<char,int> ind;
        for(int i=0;i<n;i++)
        {
            repeat = max(ind[s[i]],repeat);
            ans = max(ans,i+1-repeat);
            ind[s[i]] = i+1;
        }
        return ans;
    }
};
