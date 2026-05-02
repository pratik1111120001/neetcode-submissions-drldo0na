class Solution {
public:
    bool isPalindrome(string curr){
        int i = 0,j = curr.size() - 1;
        while(i<j){
            if(curr[i] != curr[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    void solve(vector<vector<string>> &ans,vector<string> canbe, string s, int ind){
        if(ind >= s.length()){
            ans.push_back(canbe);
            return;
        }
        string curr="";
        for(int i=ind;i<s.size();i++){
            curr += s[i];
            if(isPalindrome(curr)){
                canbe.push_back(curr);
                solve(ans,canbe,s,i+1);
                canbe.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> canbe;
        solve(ans,canbe,s,0);
        return ans;
    }
};
