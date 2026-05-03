class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
    
        vector<int> flag (wordList.size(),0);
        bool check = true;
        int res=0;
        for(auto s:wordList)
        {
            if(s==endWord)
            {
                check = false;
                break;
            }
            res++;
        }
        if(check) return 0;
        int atleast = equality(beginWord,endWord);

        queue <pair<int,int>> st;

        for(int i=0; i<wordList.size(); i++)
        {
            flag[i] = equality(beginWord,wordList[i]);
            if(flag[i]==1) st.push({i,1});
        }
        while(!st.empty())
        {
            auto[n,count] = st.front();
            st.pop();
            if(n==res) return (count+1);
            for(int j=0;j<wordList.size();j++)
            {
                if(flag[j]==1) continue;
                if(flag[j]<=(count+1))
                {
                    int t = equality(wordList[n],wordList[j]);
                    if(t==1)
                    {
                        st.push({j,count+1});
                        flag[j]=1;
                    }

                }
                
            }
        }
        return 0;


    }

    int equality(string a, string b)
    {
        int count=0;
        for(int i=0;i<a.size();i++)
        {
            if(a[i]!=b[i])
            {
                count++;
                if(count>1) return count;
            }
        }
        return count;
    }
};