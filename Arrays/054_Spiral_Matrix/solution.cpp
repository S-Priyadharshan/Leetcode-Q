#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<vector<int>>matrix={{1,2,3},{4,5,6},{7,8,9}};
    for(auto i:matrix){
        for(int j:i) cout << j << " ";
        cout << "\n";
    }

}