class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n=heights.size();
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<n-1;i++){
            if(heights[i]<heights[i+1]){

                pq.push(heights[i+1]-heights[i]);

                while(pq.size()>ladders){
                    bricks-=pq.top();
                    if(bricks<0) return i;
                    pq.pop();
                }
            }
        }
        return n-1;
    }
};