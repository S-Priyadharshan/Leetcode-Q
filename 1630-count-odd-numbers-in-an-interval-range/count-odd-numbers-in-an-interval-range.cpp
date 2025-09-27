class Solution {
public:
    int countOdds(int low, int high) {
        int len=high-low+1;
        if(low&1 && high&1)return len/2+1;
        else return len/2;
    }
};