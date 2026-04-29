class MedianFinder {
public:
    multiset<int> l,r;
    int ind;
    MedianFinder() {
        l.clear();
        r.clear();
        ind=0;
    }
    
    void addNum(int num) {
        if(ind){
            int l1 = INT_MIN;
            if(l.size())
                l1 = *(l.rbegin());
            int r1 = INT_MAX;
            if(r.size())
                r1 = *(r.begin());
            if(num>=l1 && num<=r1) r.insert(num);
            else if(num > r1) r.insert(num);
            else{
                l.erase(l.find(l1));
                l.insert(num);
                r.insert(l1);
            }
        }
        else{
            int l1 = INT_MIN;
            if(l.size())
                l1 = *(l.rbegin());
            int r1 = INT_MAX;
            if(r.size())
                r1 = *(r.begin());
            if(num>=l1 && num<=r1) l.insert(num);
            else if(num < l1) l.insert(num);
            else{
                r.erase(r.find(r1));
                r.insert(num);
                l.insert(r1);
            }
        }
        ind^=1;
    }
    
    double findMedian() {
        if(l.size() == 0) 
            return 0.0;
        double l1 = *(l.rbegin());
        if(l.size() > r.size())
            return l1;
        double r1 = *(r.begin());
        return (l1+r1)/2.0 ;
    }
};
