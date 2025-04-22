typedef long long ll;
class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        ll n=bloomDay.size();
        ll low=1;
        ll ans=-1;
        ll high=*max_element(bloomDay.begin(),bloomDay.end());
        while(low<=high){
            ll mid=low+(high-low)/2;
            ll count=0;
            ll res=0;
            for(ll i=0;i<n;i++){
                if(bloomDay[i]<=mid){
                    count++;
                    if(count>=k){
                        res++;
                        count=0;
                    }
                }else{
                    count=0;
                }
            }
            if(res>=m){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        if(ans!=-1)return ans;
        else return -1;
    }
};