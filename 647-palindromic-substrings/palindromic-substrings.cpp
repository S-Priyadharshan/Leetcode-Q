class Solution {
public:
    int countSubstrings(string s) {
        if(s.length()<=1)return 1;
        int n=s.length();
        int count=0;
        vector<vector<bool>> dp(n,vector<bool>(n));

        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                if((s[i]==s[j]) && (i-j<=2 || dp[j+1][i-1])){
                    dp[j][i]=true;
                    count++;
                }
            }
        }

        return count;
    }
};