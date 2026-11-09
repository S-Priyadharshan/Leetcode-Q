class Solution {
public:
    unordered_map<int,int>mp;
    int hashfunc(vector<int>& rem){
        int key=1;
        for(int i:rem){
            key=key*11+i;
        }
        return key;
    }

    bool valid(vector<int>& price,vector<int>& rem,vector<int>& offer){
        int sm=0;
        for(int i=0;i<rem.size();i++){
            if(offer[i]>rem[i])return false;
            sm+=(offer[i]*price[i]);
        }
        return offer.back()<=sm;
    }

    int helper(vector<int>& price,vector<vector<int>>& special,vector<int> needs){
        int hash=hashfunc(needs);
        if(mp.find(hash)!=mp.end())return mp[hash];
        int mn=INT_MAX;
        for(auto& offer:special){
            if(valid(price,needs,offer)){
                vector<int> needscopy=needs;
                for(int i=0;i<needs.size();i++){
                    needscopy[i]-=offer[i];
                }
                mn=min(mn,offer.back()+helper(price,special,needscopy));
            }
        }
        int cost=0;
        for(int i=0;i<needs.size();i++){
            cost+=(needs[i]*price[i]);
        }
        mp[hash]=min(mn,cost);
        return mp[hash];
    }

    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        mp.clear();
        return helper(price,special,needs);
    }
};