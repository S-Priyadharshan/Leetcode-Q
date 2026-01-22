class Solution {
public:
    double average(vector<int>& salary) {
        double sm=0.0;
        int mn=INT_MAX,mx=INT_MIN;
        for(int i:salary){
            sm+=i;
            if(i<mn)mn=i;
            if(i>mx)mx=i;
        }
        return (sm-mn-mx)/(salary.size()-2);
    }
};