// class Solution {
// public:
//     vector<int> sortArrayByParity(vector<int>& nums) {
//      int l=0,r=0;
//      int n=nums.size();
//      while(l<n && r<n){
//         while(l<n && nums[l]%2==0)l++;
//         while(r<n && (r<=l || nums[r]%2!=0))r++;
//         if(l<n && r<n)swap(nums[l],nums[r]);
//         r++;
//      }
//      return nums;   
//     }
// };

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i=0;
        for(int j=0;j<nums.size();j++){
            if(!(nums[j]&1)){
                swap(nums[i],nums[j]);
                i++;
            }
        }
        return nums;
    }
};
