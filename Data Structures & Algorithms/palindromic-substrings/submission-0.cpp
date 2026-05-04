class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        int ans=0;
        for(int i=0;i<n;i++){
            dp[i][i]=1;
            ans++;
        }
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                ans++;
                dp[i][i+1]=1;
            }
        }
        for(int len=2;len<=n;len++){
            for(int i=0;i<=n-len;i++){
                int j = i + len - 1;
                if(s[i]==s[j] && dp[i+1][j-1]){
                    ans++;
                    dp[i][j]=1;
                }
            }
        }
        return ans;
    }
};
