class Solution {
public:
    long long minOperations(vector<int>& a) {
        int n=a.size();
        int i=1;
        long long sm=0;
        for(int i=0;i<n-1;i++){
            if(a[i]>a[i+1])sm+=a[i]-a[i+1];
        }
        return sm;
    }
};