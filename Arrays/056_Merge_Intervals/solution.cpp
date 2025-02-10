// Solution for 056 Merge Intervals

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> merged;
    merged.push_back(intervals[0]);
    for(int i=1;i<intervals.size();i++){
        if(merged.back()[1]>=intervals[i][0])merged.back()[1]=max(merged.back()[1],intervals[i][1]);
        else merged.push_back(intervals[i]);
    }
    for(auto i:merged){
        cout << i[0] << " " << i[1] << "\n";
    }
    return 0;
}