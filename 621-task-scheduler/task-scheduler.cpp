class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if(n==0)return tasks.size();
        vector<int>freq(26,0);
        int mx=0;
        for(char ch:tasks){
            freq[ch-'A']++;
            mx=max(mx,freq[ch-'A']);
        }
        int eq=count(freq.begin(),freq.end(),mx)-1;
        int len = mx+((mx-1)*n)+eq;
        return max((int)tasks.size(),len);
    }
};