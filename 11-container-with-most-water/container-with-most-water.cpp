class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        long long ans=0;
        // for(int i=0;i<n;i++){
        //     int curr=height[i];
        //     for(int j=0;j<n;j++){
        //         int h=min(curr,height[j]);
        //         int w=abs(i-j);
        //         ans=max(ans,(h*w));
        //     }
        // }
        int i=0,j=n-1;
        while(i<j){
            long long h=min(height[i],height[j]);
            long long w=abs(i-j);
            ans=max(ans,(h*w));
            if(height[i]<=height[j])i++;
            else j--;
        }
        return ans;
    }
};