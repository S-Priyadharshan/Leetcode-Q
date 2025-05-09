typedef long long ll;
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        ll low=*max_element(weights.begin(), weights.end());;
        ll high=accumulate(weights.begin(), weights.end(), 0LL);;
        ll ans=high;
        while(low<=high){
            ll mid=low+((high-low)>>1);
            ll count=1;
            ll sum=0;
            for (int i : weights) {
                if (sum + i > mid) {
                    count++;
                    sum = i;
                } else {
                    sum += i;
                }
            }
            if(count<=days){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};