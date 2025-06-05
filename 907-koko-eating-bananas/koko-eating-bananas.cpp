typedef long long ll;
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        ll low=1;
        ll high=*max_element(piles.begin(),piles.end());
        ll ans=high;
        while(low<=high){
            ll mid=low+((high-low)>>1);
            ll count=0;
            for(int i=0;i<piles.size();i++){
                if(piles[i]%mid){
                    count+=(piles[i]/mid)+1;
                }else{
                    count+=(piles[i]/mid);
                }
            }
            if(count<=h){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};