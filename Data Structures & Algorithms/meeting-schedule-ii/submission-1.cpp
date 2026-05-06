/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        int maxi=0;
        for(auto it : intervals) maxi=max(maxi,max(it.start,it.end));
        vector<int> freq(maxi+1,0);
        for(auto it : intervals){
            cout<<it.start<<" "<<it.end<<endl;
            freq[it.start]++;
            freq[it.end]--;
        }
        int ans=freq[0];
        for(int i=1;i<=maxi;i++){
            freq[i]+=freq[i-1];
            ans=max(ans,freq[i]);
        }
        return ans;
    }
};
