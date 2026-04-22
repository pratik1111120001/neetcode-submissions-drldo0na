class Solution {
public:
    bool isHappy(int n) {
        set<int> vis;
        int curr=n;
        while(vis.find(curr) == vis.end()){
            vis.insert(curr);
            int canbe=0;
            while(curr){
                int rem = curr%10;
                canbe+=(rem*rem);
                curr/=10;
            }
            curr=canbe;
            if(curr == 1) 
                return true;
        }
        return false;
    }
};
