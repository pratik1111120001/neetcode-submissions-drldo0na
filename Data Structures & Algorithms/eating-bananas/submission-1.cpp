class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int r=INT_MAX;
        int l = 1;
        int k=0;
        while(l<=r)
        {
            int mid = l + (r-l)/2;
            int canbe=0;
            for(auto it : piles) canbe+=(it/mid + (it%mid!=0));
            if(canbe <= h) 
            {
                k=mid;
                r=mid-1;
            }
            else l = mid+1;
        }
        return k;
    }
};
