class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> startInd(26,-1),endInd(26,0);
        int n = s.size();
        for(int i=0;i<n;i++){
            if(startInd[s[i]-'a'] == -1){
                startInd[s[i]-'a']=i;
            }
            endInd[s[i]-'a']=i;
        }
        vector<int> ans;
        int start=-1,end=-1;
        for(int i=0;i<n;i++){
            if(start==-1)
                start=startInd[s[i]-'a'];
            end=max(end,endInd[s[i]-'a']);
            if(i == end){
                ans.push_back(end-start+1);
                start=-1;
                end=-1;
            }
        }
        return ans;
    }
};
