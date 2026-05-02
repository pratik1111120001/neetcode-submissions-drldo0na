class Solution {
public:
    void solve(vector<string> &ans, string canbe, int len,int curr, int ind){
        if(ind > len || curr < 0)
            return;
        if(ind == len && curr == 0)
            ans.push_back(canbe);
        solve(ans,canbe + "(", len, curr + 1, ind + 1);
        solve(ans,canbe + ")", len, curr - 1, ind + 1);
    }
    vector<string> generateParenthesis(int n) {
        int len = n*2,curr=0;
        vector<string> ans;
        string canbe = "";
        solve(ans,canbe,len,curr,0);
        return ans;
    }
};
