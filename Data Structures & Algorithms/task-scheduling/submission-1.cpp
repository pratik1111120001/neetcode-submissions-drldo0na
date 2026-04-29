class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26,0);
        for(auto it : tasks)
            freq[it-'A']++;
        set<pair<int,int>> st;
        for(int i=0;i<26;i++){
            if(freq[i]) 
                st.insert({-1*freq[i],i});
        } 
        vector<int> cooldown(26,0);
        int curr = 0;
        while(true){
            int canbe = -1;
            if(st.size()){
                pair<int,int> curr_1 = *(st.begin());
                st.erase(st.begin());
                freq[curr_1.second]--;
                canbe = curr_1.second;
                if(freq[curr_1.second]) cooldown[curr_1.second]=n+1;
            }
            bool ok=false;
            for(int i=0;i<26;i++){
                if(cooldown[i]>0){
                    cooldown[i]--;
                    if(cooldown[i] == 0){
                        st.insert({-1*freq[i],i});
                    }
                    ok=true;
                }
            }
            if(!ok && canbe == -1) break;
            curr++;
        }
        return curr;
    }
};
