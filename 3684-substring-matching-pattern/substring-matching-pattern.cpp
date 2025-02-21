class Solution {
public:
    bool hasMatch(string s, string p) {
        string pre=p.substr(0,p.find("*"));
        string suf=p.substr(p.find("*")+1);
        int x=s.find(pre);
        int y=s.find(suf,x+pre.size());
        return x!=-1 && y!=-1;     
    }
};