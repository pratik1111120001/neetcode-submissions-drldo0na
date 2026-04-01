class Solution {
public:
    bool isPalindrome(string s) {
        int i=0,j=s.size();
        j--;
        while(i<j)
        {
            bool isaphanumeric = (s[i]>='a' && s[i]<='z');
            isaphanumeric |= (s[i]>='A' && s[i]<='Z');
            isaphanumeric |= (s[i]>='0' && s[i]<='9');
            if(!isaphanumeric)
            {
                i++;
                continue;
            } 
            isaphanumeric = (s[j]>='a' && s[j]<='z');
            isaphanumeric |= (s[j]>='A' && s[j]<='Z');
            isaphanumeric |= (s[j]>='0' && s[j]<='9');
            if(!isaphanumeric)
            {
                j--;
                continue;
            }
            char s1 = s[i],s2 = s[j];
            if(s1>='A' && s1<='Z') s1-='A',s1+='a';
            if(s2>='A' && s2<='Z') s2-='A',s2+='a';
            if((s[i]>='0' && s[i]<='9' && s[j]>='0' && s[j]<='9' && s[i] == s[j]) || s1 == s2)
            {
                i++;
                j--;
                continue;
            }
            return false;
        }
        return true;
    }
};
