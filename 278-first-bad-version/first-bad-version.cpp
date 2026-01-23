// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int low=0,high=n;
        int ans=high;
        while(low<=high){
            int mid=low+((high-low)>>1);
            bool bad=isBadVersion(mid);
            if(bad){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};