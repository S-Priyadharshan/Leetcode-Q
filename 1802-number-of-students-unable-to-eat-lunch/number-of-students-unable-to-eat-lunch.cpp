class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n=students.size();
        map<int,int>mp;
        for(int i:students){
            mp[i]++;
        }
        for(int i:sandwiches){
            mp[i]--;
            if(mp[i]<0)return n;
            n--;
        }
        return n;
    }
};