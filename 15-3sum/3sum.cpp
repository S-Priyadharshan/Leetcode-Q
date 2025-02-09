class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        set<vector<int>> s;
        for(int i=0;i<nums.size();i++){
            int j=i+1;
            int k=nums.size()-1;
            while(j<k){
                int sumn=nums[i]+nums[j]+nums[k];
                if(sumn==0){
                    s.insert({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                }else if(sumn<0){
                    j++;
                }else{
                    k--;
                }
            }
        }
        for(auto z:s){
            ans.push_back(z);
        }
        return ans;
    }
};