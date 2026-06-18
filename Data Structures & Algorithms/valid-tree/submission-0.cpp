class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n-1)
            return false;

        vector<vector<int>> adj(n);
        for(auto& e : edges){
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> visited(n , false);

        dfs(0 , adj , visited);

        for(bool node : visited){
            if(!node){
                return false;
            }
        }
        return true;
    }
    void dfs(int node , vector<vector<int>>& adj , vector<bool>& visited){
        visited[node] = true;

        for(int ngbr : adj[node]){
            if(!visited[ngbr]){
                dfs(ngbr , adj , visited);
            }
        }
    }

};
