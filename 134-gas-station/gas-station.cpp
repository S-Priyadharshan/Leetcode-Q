class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int totg=0,totc=0,curr=0,ans=0;
        for(int i=0;i<n;i++){
            totg+=gas[i];
            totc+=cost[i];
            curr+=(gas[i]-cost[i]);
            if(curr<0){
                ans=(i+1);
                curr=0;
            }
        }
        if(totg<totc)return -1;
        else return ans;
    }
};