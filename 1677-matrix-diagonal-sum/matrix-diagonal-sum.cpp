class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n=mat.size();
        int left=0,right=n-1;
        int sm=0,j=0;
        while(left<n){
            if(left==right){
                sm+=mat[left][j];
            }else{
                sm+=mat[left][j];
                sm+=mat[j][right];
            }
            left++;
            j++;
            right--;
        }
        return sm;
    }
};