class Solution {
public:
    int minMoves(vector<int>& nums) {
        int count=0;
        int mn=*min_element(nums.begin(),nums.end());
        for(int i:nums)count+=(i-mn);
        return count;
    }
};