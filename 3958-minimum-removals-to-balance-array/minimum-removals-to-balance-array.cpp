class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int right=0;
        int maxlen=0;
        for(int i=0;i<n;i++){
            long long val=nums[i]*1ll*k;
            while(right<n && nums[right]<=val){
                maxlen=max(maxlen,right-i+1);
                right++;
            }
        }
        return n-maxlen;
    }
};