class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freq(26,0);
        for(auto it : s1) freq[it-'a']++;
        int i=0,n=s1.size();
        for(auto it : s2)
        {
            freq[it-'a']--;
            if(i >= (n-1))
            {
                if(i>=n) freq[s2[i-n]-'a']++;
                bool ok = true;
                for(int j=0;j<26;j++) ok &= (freq[j]==0);
                if(ok) return true;
            }
            i++;
        } 
        return false;
    }
};
