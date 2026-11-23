class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();

        auto check = [&](int mid){
            int row=n-1;
            int col=0;
            int count=0;
            while(row>=0 && col<n){
                if(matrix[row][col]<=mid){
                    count+=(row+1);
                    col++;
                }else{
                    row--;
                }
            }
            return count;
        };

        int low=matrix[0][0];
        int high=matrix[n-1][n-1];
        int ans=high;
        while(low<=high){
            int mid=low+((high-low)>>1);

            int cnt=check(mid);

            if(cnt>=k){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};