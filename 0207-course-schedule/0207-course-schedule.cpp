class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        queue<int>q;
        vector<vector<int>>adj(numCourses);
        for(int i=0;i<n;i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int>indegree(numCourses,0);
        for(int i=0;i<adj.size();i++){
            for(int &v : adj[i]){
                indegree[v]++;
            }
        }
        int count = 0;
        for(int i=0;i<numCourses;i++){
            if(indegree[i] == 0){
                q.push(i);
                count++;
            }
        }
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int &v : adj[u]){
                indegree[v]--;
                if(indegree[v] == 0){
                    q.push(v);
                    count++;
                }
            }
        }
        if(count == numCourses){
            return true;
        }
        return false;
    }
};