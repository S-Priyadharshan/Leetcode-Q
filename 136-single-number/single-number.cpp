class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // int ans=0;
        // for(int i=0;i<nums.size();i++){
        //     ans^=nums[i];
        // }
        // return ans;
        unordered_map<int,int>mp;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(auto j:nums){
            if(mp[j]==1){
                ans=j;
                break;
            }
        }
        return ans;
    }
};