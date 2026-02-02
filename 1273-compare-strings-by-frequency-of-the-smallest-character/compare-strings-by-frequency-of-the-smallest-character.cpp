class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int>q;
        vector<int>w;
        int n=words.size();
        vector<int>res;
        auto f=[](string s){
            char mn=*min_element(s.begin(),s.end());
            int cnt=0;
            for(char ch:s)if(ch==mn)cnt++;
            return cnt;
        };
        for(string s:queries){
            q.push_back(f(s));
        }
        for(string wr:words){
            w.push_back(f(wr));
        }
        sort(w.begin(),w.end());
        for(int i:q){
            int it=upper_bound(w.begin(),w.end(),i)-w.begin();
            res.push_back(n-it);
        }
        return res;
    }
};