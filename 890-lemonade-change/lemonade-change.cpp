class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int c5=0;
        int c10=0;
        int c20=0;
        for(int i:bills){
            if(i==5)c5++;
            else if(i==10)c10++,c5--;
            else if(c10>0)c10--,c5--;
            else c5-=3;
            if(c5<0)return false;
        }
        return true;
    }
};