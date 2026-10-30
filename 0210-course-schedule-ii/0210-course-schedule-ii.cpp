class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        for(auto &vec : prerequisites){
            int a = vec[0];
            int b = vec[1];
            adj[b].push_back(a);
        }
        vector<int>indegree(numCourses,0);
        vector<int>result;
        queue<int>q;

        for(int i=0;i<numCourses;i++){
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
            result.push_back(u);
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
            return result;
        }
        return {};
    }
};