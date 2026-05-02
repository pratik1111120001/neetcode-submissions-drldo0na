class Solution {
public:
    void solve(string digits, vector<string> &ans, string curr, int ind, map<char,string> &keypad){
        if(ind == digits.size() && curr.size()){
            ans.push_back(curr);
            return;
        }
        for(auto it : keypad[digits[ind]]){
            curr+=it;
            solve(digits,ans,curr,ind+1,keypad);
            curr=curr.substr(0,curr.size()-1);
        }
    }
    vector<string> letterCombinations(string digits) {
        map<char,string> keypad;
        keypad['1']="";
        keypad['2']="abc";
        keypad['3']="def";
        keypad['4']="ghi";
        keypad['5']="jkl";
        keypad['6']="mno";
        keypad['7']="pqrs";
        keypad['8']="tuv";
        keypad['9']="wxyz";
        keypad['*']="";
        keypad['0']="+";
        keypad['#']="";

        vector<string> ans;
        string curr="";
        solve(digits,ans,curr,0,keypad);
        return ans;
    }
};
