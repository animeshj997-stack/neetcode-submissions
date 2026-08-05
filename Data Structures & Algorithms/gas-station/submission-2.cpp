class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sumg=0,sumc=0;
        for(int i=0;i<gas.size();i++){
            sumg+=gas[i];
            sumc+=cost[i];
        }

        if(sumg<sumc) return -1;
        
        int idx=0;
        int fuel=0;
        for(int i=0;i<gas.size();i++){
            fuel+=gas[i]-cost[i];
            if(fuel<0){
                fuel=0;
                idx=i+1;
            }
        }

        return (idx==gas.size()) ? -1 : idx;
    }
};
