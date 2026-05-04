class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        int maxLen=1,maxInd=0;
        for(int i=0;i<n;i++) dp[i][i]=1;
        for(int i=0;i<n-1;i++){
            if(s[i] == s[i+1]){
                maxLen=2;
                maxInd=i;
                dp[i][i+1]=1;
            }
        }
        for(int len=2;len<=n;len++){
            for(int i=0;i<=n-len;i++){
                int j = i + len - 1;
                if(s[i] == s[j] && dp[i+1][j-1]){
                    dp[i][j]=1;
                    maxLen=len;
                    maxInd=i;
                }
            }
        }
        return s.substr(maxInd,maxLen);
    }
};
