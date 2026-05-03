class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        map<string,int> freq;
        for(auto it : wordList)
            freq[it]=1;
        int ans = 0;
        queue<pair<string,set<string>>> q;
        set<string> s;
        s.insert(beginWord);
        q.push({beginWord,s});
        while(q.size()){
            pair<string,set<string>> curr = q.front();
            q.pop();
            s = curr.second;
            beginWord = curr.first;
            if(beginWord == endWord){
                ans=s.size();
                break;
            }
            for(int j=0;j<beginWord.size();j++){ 
                for(int i=0;i<26;i++){
                    char ch = 'a' + i;
                    if(ch != beginWord[j]){
                        char prev = beginWord[j];
                        beginWord[j] = ch;
                        if(freq[beginWord] && s.find(beginWord) == s.end()){
                            s.insert(beginWord);
                            q.push({beginWord,s});
                            s.erase(s.find(beginWord));
                        }
                        beginWord[j] = prev;
                    }
                }
            }
        }
        return ans;
    }
};
