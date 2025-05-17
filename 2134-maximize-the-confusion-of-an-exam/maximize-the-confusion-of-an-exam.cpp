// class Solution {
// public:
//     bool pos(string &s,int k,int len,char x){
//         int count=0;
//         int n=s.size();
//         for(int i=0;i<n;i++){
//             if(s[i]!=x)count++;
//             if(i>=len){
//                 if(s[i-len]!=x)count--;
//             }
//             if(i>=n-1&&count<=k)return true;
//         }
//         return false;
//     }
//     int maxConsecutiveAnswers(string answerKey, int k) {
//         int low=0,high=answerKey.size(),ans=0;
//         while(low<=high){
//             int mid=low+((high-low)>>1);
//             if(pos(answerKey,k,mid,'T')||pos(answerKey,k,mid,'F')){
//                 ans=mid;
//                 low=mid+1;
//             }else{
//                 high=mid-1;
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    bool isValid(string &s, int k, int len, char ch) {
        int count = 0, left = 0;
        for (int right = 0; right < s.size(); ++right) {
            if (s[right] != ch) ++count;
            if (right - left + 1 > len) {
                if (s[left] != ch) --count;
                ++left;
            }
            if (right - left + 1 == len && count <= k) return true;
        }
        return false;
    }

    int maxConsecutiveAnswers(string answerKey, int k) {
        int low = 1, high = answerKey.size(), res = 0;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (isValid(answerKey, k, mid, 'T') || isValid(answerKey, k, mid, 'F')) {
                res = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return res;
    }
};
