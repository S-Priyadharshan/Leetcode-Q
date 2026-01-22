class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int cnt=0;
        for(int i:nums){
            int d=log10(i)+1;
            if(!(d&1))cnt++;
        }
        return cnt;
    }
};