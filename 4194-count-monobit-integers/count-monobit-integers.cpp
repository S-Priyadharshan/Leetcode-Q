class Solution {
public:
    int countMonobit(int n) {
        if(n<1)return 1;
        if (n==1) return 2;
        cout<<log2(n)<<"\n";
        return (int)log2(n+1)+1;
    }
}; 