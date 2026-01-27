class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if(nums.size()==1)return 0;
        int curr=0,ans=0;
        for(int i=0;i<nums.size()-2;i++){
            if(nums[i]-nums[i+1]==nums[i+1]-nums[i+2]){
                curr++;
                ans+=curr;
            }else{
                curr=0;
            }
        }
        return ans;
    }
};