class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n%2==0){
            return fmod(log2(n),1)==0;
        }else{
            if(n==1) return true;
            else return false;
        }
    }
};