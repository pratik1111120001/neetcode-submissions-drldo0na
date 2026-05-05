class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int startInd=-1,currGas=0,currInd=0,lastIndCnt=0,found=0;
        int n = gas.size();
        while(lastIndCnt<3){
            if(currInd == startInd){
                found=1;
                break;
            }
            if(startInd == -1)
                startInd = currInd;
            currGas+=gas[currInd];
            if(currGas < cost[currInd]){
                startInd=-1;
                currGas=0;
            }
            else{
                currGas-=cost[currInd];
            }
            currInd++;
            currInd%=n;
            if(currInd == n-1)
                lastIndCnt++;
        }
        if(!found)
            startInd = -1;
        return startInd;
    }
};
