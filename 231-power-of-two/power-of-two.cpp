class Solution {
public:
    bool isPowerOfTwo(int n) {
        // return fmod(log2(n),1)==0;
        return n>0 && !(n&n-1);
    }
};