class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        vector<vector<int>> adj(26);
        vector<int> inDeg(26,-1);
        set<char> st;
        int n = words.size();
        for(auto x : words){
            for(auto it : x){
                st.insert(it);
                int u = it - 'a';
                inDeg[u]=0;
            }
        }
        for(int i=0;i<n-1;i++){
            // for(int j=i+1;j<n;j++){
            int j = i+1;
            bool flag = false;
                for(int k=0;k<min(words[i].size(),words[j].size());k++){
                    if(words[i][k] != words[j][k]){
                        int u = words[i][k] - 'a';
                        int v = words[j][k] - 'a';
                        bool ok=true;
                        flag=true;
                        for(auto it : adj[u]){
                            if(it == v){
                                ok=false;
                            }
                        }
                        if(ok){
                            adj[u].push_back(v);
                            inDeg[v]++;
                        }
                        break;
                    }
                }
                if(!flag && min(words[i].size(),words[j].size()) == words[j].size() && words[i].size()!=words[j].size()){
                    return "";
                }
            // }
        }
        string ans="";
        queue<int> q;
        for(int i=0;i<26;i++) if(!inDeg[i]) q.push(i);
        while(q.size()){
            int curr = q.front();
            ans+=('a'+curr);
            q.pop();
            for(auto it : adj[curr]){
                inDeg[it]--;
                if(!inDeg[it]) q.push(it);
            }
        }
        return ans.size() == st.size() ? ans : "";
    }
};
