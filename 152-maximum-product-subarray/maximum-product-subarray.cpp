class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currmx=nums[0];
        int currmn=nums[0];
        int ans=nums[0];
        for(int i=1;i<nums.size();i++){
            int x=nums[i];
            if(x<0)swap(currmx,currmn);
            currmx=max(x,currmx*x);
            currmn=min(x,currmn*x);
            ans=max(ans,currmx);
        }
        return ans;
    }
};