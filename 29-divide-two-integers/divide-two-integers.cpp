class Solution {
public:
    int divide(int dividend, int divisor) {
        // Use of labs for absolute of long long integers
        // Use of short count as a substitute for int count
        // d<<(count+1) operators associativity
        bool sign = true;
        if(dividend==divisor)return 1;
        if(dividend>=0&&divisor<0)sign=false;
        if(dividend<=0&&divisor>0)sign=false;
        long ans=0;
        long n=labs(dividend);
        long d=labs(divisor);
        while(n>=d){
            short count=0;
            while(n>(d<<(count+1))){
                count++;
            }
            ans+=(1<<count);
            n-=d*(1<<count);
        }
        if(ans>INT_MAX&&sign)return INT_MAX;
        if(ans<=INT_MIN&&sign==false)return INT_MIN;

        return sign ? ans:ans*-1;
    }
};