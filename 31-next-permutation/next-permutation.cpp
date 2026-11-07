class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int idx=-1;
        for(int i=n-1;i>0;i--){
            if(nums[i]>nums[i-1]){
                idx=i-1;
                break;
            }
        }
        if(idx==-1)return reverse(nums.begin(),nums.end());
        int lb=idx+1;
        for(int i=idx+1;i<n;i++){
            if(nums[i]>nums[idx] && nums[i]<=nums[lb])lb=i;
        };
        swap(nums[idx],nums[lb]);
        return reverse(nums.begin()+idx+1,nums.end());
    }
};