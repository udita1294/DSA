class Solution {
public:
    // Now using BFS
    void BFS(vector<vector<int>>&adj,int u,vector<bool>&visited){
        queue<int>q;
        q.push(u);
        visited[u] = true;
        while(!q.empty()){
            int N = q.front();
            q.pop();
            for(int &v : adj[N]){
                if(!visited[v]){
                    q.push(v);
                    visited[v] = true;
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>>adj(n);
        vector<bool>visited(n,false);
        int count = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j] == 1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        for(int i=0;i<n;i++){
            if(!visited[i]){
                BFS(adj,i,visited);
                count++;
            }
        }
        return count;
    }
};