class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // int n=nums.size();
        // set<vector<int>> res;
        // for(int i=0;i<n;i++){
        //     vector<int>curr;
        //     for(int j=i;j<n;j++){
        //         curr.push_back(nums[j]);
        //     }
        //     res.insert(curr);
        // }
        // vector<vector<int>>ans;
        // ans.push_back({});
        // for(auto i:res)ans.push_back(i);
        // return ans;
        vector<vector<int>> res = {{}};
        for (int num : nums) {
            int sz = res.size();
            for (int i = 0; i < sz; ++i) {
                vector<int> temp = res[i];
                temp.push_back(num);
                res.push_back(temp);
            }
        }
        return res;
    }
};