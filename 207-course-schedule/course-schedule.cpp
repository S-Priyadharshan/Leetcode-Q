class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        // vector<bool>
        vector<int>indegree(numCourses);
        for(auto vec:prerequisites){
            indegree[vec[0]]++;
            adj[vec[1]].push_back(vec[0]);
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0)q.push(i);
        }
        if(q.empty())return false;
        int cnt=0;
        while(!q.empty()){
            int sz=q.size();
            cnt+=sz;
            for(int i=0;i<sz;i++){
                int node = q.front();
                q.pop();
                for(int nei:adj[node]){
                    indegree[nei]--;
                    if(indegree[nei]==0)q.push(nei);
                }
            }
        }

        if(cnt==numCourses)return true;
        return false;
    }
};