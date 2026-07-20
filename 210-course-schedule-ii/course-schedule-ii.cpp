class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses);
        for(auto vec: prerequisites){
            indegree[vec[0]]++;
            adj[vec[1]].push_back(vec[0]);
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0)q.push(i);
        }
        vector<int>ans;
        while(!q.empty()){
            int node = q.front();
            ans.push_back(node);
            q.pop();
            for(int nei:adj[node]){
                indegree[nei]--;
                if(indegree[nei]==0)q.push(nei);
            }
        }
        if(ans.size()!=numCourses) return {};
        return ans;
    }
};