class Solution {
public:
    bool check(vector<int> &freq, vector<int> &freq1, string t)
    {
        bool ok = true;
        for(auto it : t)
        {
            if(it>='a' && it<='z') ok &= (freq[it-'a'] <= 0);
            else ok &= (freq1[it-'A'] <= 0);
            if(!ok) break;
        }
        return ok;
    }
    string minWindow(string s, string t) {
        vector<int> freq(26,0),freq1(26,0);
        for(auto it : t)
        {
            if(it>='a' && it<='z') freq[it-'a']++;
            else freq1[it-'A']++;
        }
        int start=-1,end=-1,j=0,n=s.size(),m=t.size();
        for(int i=0;i<n;i++)
        {
            if(s[i]>='a' && s[i]<='z') freq[s[i]-'a']--;
            else freq1[s[i]-'A']--;
            if(i-j+1 >= m)
            {
                while(check(freq,freq1,t))
                {
                    if(end==-1)
                        start=j,end=i;
                    else if(i-j < end-start)
                        start=j,end=i;
                    if(s[j]>='a' &&  s[j]<='z') freq[s[j]-'a']++;
                    else freq1[s[j]-'A']++;
                    j++;
                }
            }
        }
        string ans="";
        if(end!=-1)
            ans=s.substr(start,end-start+1);
        return ans;
    }
};
