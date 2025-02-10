class Solution {
public:
    int hammingWeight(int n) {
        // return __builtin_popcount(n);
        // Alternate approach using Brian Kernighan's Algorithm

        int count=0;
        while(n){
            n=n&(n-1);
            count++;
        }
        return count;
    }
};