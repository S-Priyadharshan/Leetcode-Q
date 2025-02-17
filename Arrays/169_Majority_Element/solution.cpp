// Solution for 169 Majority Element

#include <bits/stdc++.h>
using namespace std;

int main() {
    // Apart from counting frequencies, More efficient method
    vector<int> nums = {2,2,1,1,1,2,2};
    sort(nums.begin(),nums.end());
    cout << nums[nums.size()/2] << "\n";
    return 0;
}