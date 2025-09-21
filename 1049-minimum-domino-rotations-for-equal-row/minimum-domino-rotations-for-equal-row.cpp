class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n=tops.size();
        int a=tops[0],b=bottoms[0];
        int cat=0,cab=0,cbt=0,cbb=0;
        bool pa=true,pb=true;
        for(int i=0;i<n;i++){
            if(tops[i]!=a&&bottoms[i]!=a){
                pa=false;
                break;
            }
            else if(tops[i]!=a)cat++;
            else if(bottoms[i]!=a)cab++;
        }
        for(int i=0;i<n;i++){
            if(tops[i]!=b&&bottoms[i]!=b){
                pb=false;
                break;
            }
            else if(tops[i]!=b)cbt++;
            else if(bottoms[i]!=b)cbb++;
        }
        int ans=INT_MAX;
        if(pa)ans=min(ans,min(cat,cab));
        if(pb)ans=min(ans,min(cbt,cbb));
        return ans==INT_MAX ? -1:ans;
    }
};

