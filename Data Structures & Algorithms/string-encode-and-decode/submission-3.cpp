class Solution {
public:

    string encode(vector<string>& strs) {
        string ans="";
        for(auto it : strs)
        {
            int len = it.size();
            ans+=to_string(len);
            ans+="&";
        }
        // ans = ans.substr(0,ans.size()-1);
        ans+="=";
        for(auto it : strs)
            ans+=it;
        cout<<ans<<endl;
        return ans;
    }

    vector<string> decode(string s) {
        vector<int> lens;
        int i=0,len=s.size(),curr=0;
        for(;s[i] != '='; i++)
        {
            if(s[i]=='&')
            {
                lens.push_back(curr);
                curr=0;
            }
            else
            {
                curr*=10;
                curr+=(s[i] - '0');
            }
        }
        i++;
        vector<string> ans;
        int j=0,n=lens.size();
        string s1 = "";
        for(auto it : lens) cout<<it<<endl;
        cout<<i<<endl;
        for(;i < len;i++)
        {
            int k=0;
            if(lens[j] == 0) 
            {
                ans.push_back(s1);
                j++;
                i--;
                continue;
            }
            while(k < lens[j]-1) s1+=s[i],i++,k++;
            s1+=s[i];
            j++;
            ans.push_back(s1);
            s1="";
        }
        while(j<lens.size()) ans.push_back(s1),j++;
        return ans;
    }
};
