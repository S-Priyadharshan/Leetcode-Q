class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>ans;
        if(nums.size()<2)return ans;
        for(int i=0;i<nums.size();i++){
            int x=abs(nums[i]);
            if(nums[x-1]<0){
                ans.push_back(x);
            }else{
                nums[x-1]*=-1;
            }
        }
        return ans;
    }
};