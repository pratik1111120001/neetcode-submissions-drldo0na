class KthLargest {
public:
    multiset<int> vals;
    int sz;
    KthLargest(int k, vector<int>& nums) {
        sz = k;
        for(auto it : nums)
            vals.insert(it);
        while(vals.size() > sz) vals.erase(vals.begin());
    }
    
    int add(int val) {
        vals.insert(val);
        if(vals.size() > sz) vals.erase(vals.begin());
        return (*(vals.begin()));
    }
};
