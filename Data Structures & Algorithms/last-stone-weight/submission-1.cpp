class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        multiset<int> rem;
        for(auto it : stones) rem.insert(it);
        while(rem.size() > 1)
        {
            int a = *(rem.rbegin());
            auto it = rem.end();
            --it;
            rem.erase(it);
            int b = *(rem.rbegin());
            it = rem.end();
            --it;
            rem.erase(it);
            if(a-b > 0) rem.insert(a-b);
        }
        return (rem.size()? (*(rem.begin())) : 0);
    }
};
