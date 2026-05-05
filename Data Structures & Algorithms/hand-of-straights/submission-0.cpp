class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        unordered_map<int,int> freq;
        set<int> st;
        for(auto it : hand){
            freq[it]++;
            st.insert(it);
        }
        while(st.size()){
            int curr = *(st.begin());
            for(int i=0;i<groupSize;i++){
                if(!freq[curr+i])
                    return false;
                freq[curr+i]--;
                if(!freq[curr+i])
                    st.erase(st.find(curr+i));
            }
        }
        return true;
    }
};
