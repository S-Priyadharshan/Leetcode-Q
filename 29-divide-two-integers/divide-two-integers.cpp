class Solution {
public:
    int divide(int dividend, int divisor) {
        bool sign = true;
        if(dividend==divisor)return 1;
        if(dividend>=0&&divisor<0)sign=false;
        if(dividend<=0&&divisor>0)sign=false;
        long ans=0;
        long n=labs(dividend);
        long d=labs(divisor);
        while(n>=d){
            int count=0;
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