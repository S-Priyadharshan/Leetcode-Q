class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int sum=0,count=0;
        map<int,int>mp;
        mp[0]=1;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(mp[sum-k]){
                count+=mp[sum-k];
            }
            mp[sum]++;
        }
        return count;
    }
};