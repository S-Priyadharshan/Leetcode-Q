class Solution {
public:
    int numSquares(int n) {
        int sz=sqrt(n);
        vector<int>sqs;
        for(int i=1;i<=sz;i++){
            sqs.push_back(i*i);
        }
        vector<int>dp(n+1,INT_MAX);
        dp[0]=0;
        for(int i=1;i<=n;i++){
            for(int j=0;j<sqs.size();j++){
                if(i>=sqs[j] && dp[i-sqs[j]]!=INT_MAX){
                    dp[i]=min(dp[i],dp[i-sqs[j]]+1);
                }
            }
        }
        if(dp[n]==INT_MAX)return 0;
        else return dp[n];
    }
};