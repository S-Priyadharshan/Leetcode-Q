class Solution {
public:
    using ll = long long;
    ll count=0;

    void merge(int low,int mid,int high,vector<int>& nums){
        int j=mid+1;

        for(int i=low;i<=mid;i++){
            while(j<=high && nums[i]> 2LL * nums[j])j++;
            count+=(j-(mid+1));
        }

        vector<int>left(nums.begin()+low,nums.begin()+mid+1);
        vector<int>right(nums.begin()+mid+1,nums.begin()+high+1);

        j=0;
        int i=0,k=low;

        while(i<left.size() && j<right.size()){
            if(left[i]<=right[j]){
                nums[k++]=left[i++]; 
            }else{
                nums[k++]=right[j++];
            }
        }

        while(i<left.size())nums[k++]=left[i++];
        while(j<right.size())nums[k++]=right[j++];
    }

    void mergesort(int low,int high,vector<int>& nums){
        if(low>=high)return;
        int mid=low+((high-low)>>1);
        mergesort(low,mid,nums);
        mergesort(mid+1,high,nums);
        merge(low,mid,high,nums);
    }
    int reversePairs(vector<int>& nums) {
        mergesort(0,nums.size()-1,nums);        
        return count;
    }
};