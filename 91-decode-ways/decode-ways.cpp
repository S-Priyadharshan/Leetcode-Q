class Solution {
public:
    string str;
    vector<int>memo;
    int numDecodings(string s) {
        int n=s.size();
        str=s;
        memo.resize(str.size(),-1);
        return helper(0,n);
    }
    int helper(int idx,int n){
        if(idx>=n)return 1;
        if(memo[idx]!=-1)return memo[idx];
        if(str[idx]=='0')return 0;
        int cnt=helper(idx+1,n);
        if(idx+1<n && (str[idx]=='1' || (str[idx]=='2' && str[idx+1]<='6'))){
            cnt+=(helper(idx+2,n));
        }
        memo[idx]=cnt;
        return cnt;
    }
};