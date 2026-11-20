class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        // int n=grid.size();
        // int m=grid[0].size();
        // vector<vector<int>> dp(n,vector<int>(m,0));
        // dp[0][0]=grid[0][0];
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         int mn=INT_MAX;
        //         if(i-1>=0)mn=min(mn,dp[i-1][j]);
        //         if(j-1>=0)mn=min(mn,dp[i][j-1]);
        //         if(i!=0 || j!=0)dp[i][j]+=(mn+grid[i][j]);
        //     }
        // }
        // return dp[n-1][m-1];

        int n=grid.size();
        int m=grid[0].size();

        vector<int>dp(m,0);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0)dp[j] = grid[i][j];
                else if(i==0)dp[j]=dp[j-1]+grid[i][j];
                else if(j==0)dp[j]=dp[j]+grid[i][j];
                else dp[j]=min(dp[j],dp[j-1])+grid[i][j];
            }
        }
        
        return dp[m-1];
    }
};