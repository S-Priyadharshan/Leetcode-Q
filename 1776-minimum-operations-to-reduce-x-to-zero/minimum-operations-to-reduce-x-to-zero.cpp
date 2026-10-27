class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sm=accumulate(nums.begin(),nums.end(),0);
        int l=0;
        int val=0;
        int ans=-1;
        for(int r=0;r<nums.size();r++){
            val+=nums[r];
            while(l<=r && (sm-val)<x){
                val-=nums[l];
                l++;
            }
            if((sm-val)==x){
                ans=max(ans,r-l+1);
            }
        }
        if(ans==-1)return -1;
        else return nums.size()-ans;
    }
};