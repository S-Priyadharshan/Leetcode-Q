class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int i = 0;
        vector<int> sn, sp, res;

        while (i < nums.size() && nums[i] < 0) {
            sn.push_back(nums[i] * nums[i]);
            i++;
        }
        while (i < nums.size()) {
            sp.push_back(nums[i] * nums[i]);
            i++;
        }

        i = sn.size() - 1;
        int j = 0;
        while (i >= 0 && j < sp.size()) {
            if (sn[i] < sp[j]) {
                res.push_back(sn[i]);
                i--;
            } else {
                res.push_back(sp[j]);
                j++;
            }
        }

        while (i >= 0) {
            res.push_back(sn[i]);
            i--;
        }
        while (j < sp.size()) {
            res.push_back(sp[j]);
            j++;
        }

        return res;
    }
};
