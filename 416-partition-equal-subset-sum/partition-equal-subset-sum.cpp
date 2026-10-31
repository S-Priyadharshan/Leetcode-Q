class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sm=accumulate(nums.begin(),nums.end(),0);
        if(sm&1)return false;

        int target=sm/2;
        int n=nums.size();

        vector<bool> dp(target+1,false);
        dp[0]=true;
        for(int i=0;i<n;i++){
            for(int w=target;w>=nums[i];w--){
                dp[w]=dp[w]||dp[w-nums[i]];
            }
        }

        return dp[target];
    }
};