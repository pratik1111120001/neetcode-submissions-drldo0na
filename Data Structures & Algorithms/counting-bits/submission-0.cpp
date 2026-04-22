class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1,0);
        for(int i=n;i>=1;i--)
        {
            if(!ans[i]){
                int curr = i;
                vector<int> canbe;
                int res=0;
                while(curr && !ans[curr]){
                    canbe.push_back(curr);
                    curr&=(curr-1);
                    res++;
                }
                res+=ans[curr];
                for(auto it : canbe){
                    ans[it] = res;
                    res--;
                }
            }
        }
        return ans;
    }
};
