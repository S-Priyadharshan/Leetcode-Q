// class Solution {
// public:
//     string reverseOnlyLetters(string s) {
//         int left = 0, right = s.size() - 1;
//         while(left < right) {
//             if(!isalpha(s[left])) left++;
//             else if(!isalpha(s[right])) right--;
//             else {
//                 swap(s[left], s[right]);
//                 left++;
//                 right--;
//             }
//         }
//         return s;
//     }
// };

class Solution {
public:
    string reverseOnlyLetters(string s) {
        int n=s.size();
        int left=0,right=n-1;
        while(left<right){
            if(!((s[left]>='a'&&s[left]<='z')||(s[left]>='A'&&s[left]<='Z'))){
                left++;
            }else if(!((s[right]>='a'&&s[right]<='z')||(s[right]>='A'&&s[right]<='Z'))){
                right--;
            }else{
                swap(s[left],s[right]);
                left++;
                right--;
            }
        }
        return s;
    }
};