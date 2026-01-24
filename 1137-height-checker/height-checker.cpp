class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int n=heights.size();
        vector<int> freq(101,0);
        for(int i:heights)freq[i]++;
        int res=0,curr=0;
        for(int i=0;i<n;i++){
            while(freq[curr]==0)curr++;
            if(curr!=heights[i])res++;
            freq[curr]--;
        }
        return res;
    }
};