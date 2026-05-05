class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool first=false,second=false,third=false;
        for(auto it : triplets){
            if(target[0] == it[0] && target[1] >= it[1] && target[2] >= it[2])
                first=true;
            if(target[1] == it[1] && target[0] >= it[0] && target[2] >= it[2])
                second=true;
            if(target[2] == it[2] && target[0] >= it[0] && target[1] >= it[1])
                third=true;
        }
        return (first && second && third);
    }
};
