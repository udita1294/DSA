class Solution {
public:
    bool isBipartiteBFS(vector<vector<int>>&adj,int u,vector<int>&color,int currColor){
        queue<int>q;
        q.push(u);
        color[u] = currColor;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int &v : adj[u]){
                if(color[v] == color[u]){
                    return false;
                }else if(color[v] == -1){
                    color[v] = 1 - color[u];
                    q.push(v);
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int>color(V,-1);
        for(int i=0;i<V;i++){
            if(color[i] == -1){
                if(isBipartiteBFS(graph,i,color,1) == false){
                    return false;
                }
            }
        }
        return true;
    }
};