class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int j=0;
        int sm=0;
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            sm+=nums[i];
            while(sm>=target && j<=i){
                if(sm>=target)ans=min(ans,i-j+1);
                sm-=nums[j];
                j++;
            }
        }
        if(ans!=INT_MAX)return ans;
        else return 0;
    }
};