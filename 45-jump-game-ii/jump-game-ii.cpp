class Solution {
public:
    int jump(vector<int>& a) {
        // int n=a.size()-1;
        // int i=0;
        // int ans=0;
        // while((i+a[i])<n){
        //     int mv=0,mi=0;
        //     for(int j=(i+1);j<(i+a[i]);j++){
        //         if(a[j]>mv){
        //             mv=a[j];
        //             mi=j;
        //         }
        //     }
        //     i=mi;
        //     ans++;
        // }
        // return ans+1;

        int n=a.size()-1;
        if(n==0)return 0;

        int i=0,ans=0;

        while(i<n){
            if(i+a[i]>=n){
                ans++;
                break;
            }
            int idx=i;
            int mxv=0;

            for(int j=i+1;j<=(i+a[i]);j++){
                if(j+a[j]>mxv){
                    mxv=j+a[j];
                    idx=j;
                }
            }

            i=idx;
            ans++;
        }    
        return ans;
    }
};