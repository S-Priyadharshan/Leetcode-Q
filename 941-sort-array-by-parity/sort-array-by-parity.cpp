class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
     int l=0,r=0;
     int n=nums.size();
     while(l<n && r<n){
        while(l<n && nums[l]%2==0)l++;
        while(r<n && (r<=l || nums[r]%2!=0))r++;
        if(l<n && r<n)swap(nums[l],nums[r]);
        r++;
     }
     return nums;   
    }
};