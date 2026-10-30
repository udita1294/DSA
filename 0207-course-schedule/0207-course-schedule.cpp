class Solution {
public:
// using dfs cycle detection
    bool isCycle(vector<vector<int>>&adj,int u,vector<bool>&visited,vector<bool>&inRecursion){
        visited[u] = true;
        inRecursion[u] = true;
        for(int &v : adj[u]){
            if(!visited[v] && isCycle(adj,v,visited,inRecursion)){
                return true;
            }else if(inRecursion[v] == true){
                return true;
            }
        }
        inRecursion[u] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        vector<vector<int>>adj(numCourses);
        vector<bool>visited(numCourses,false);
        vector<bool>inRecursion(numCourses,false);
        for(int i=0;i<n;i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        for(int i=0;i<numCourses;i++){
            if(!visited[i] && isCycle(adj,i,visited,inRecursion)){
                //if cycle return false
                return false;
            }
        }
        return true;
    }
};