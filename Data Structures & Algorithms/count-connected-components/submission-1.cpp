class Solution {
public:
    void dfs(int node , vector<vector<int>>& adj , vector<bool>& visited){
        visited[node] = true;

        for(int ngbr : adj[node]){  
            if(!visited[ngbr]){
                dfs(ngbr , adj , visited);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);     // create adjecency list

        for(auto& e : edges){
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> visited(n , false);    //create visited array
        int components = 0;     //component counter

        for(int i=0 ; i<n ; i++){       //loop through every node
            if(!visited[i]){
                components++;       //increment counter 

                dfs(i , adj , visited);
            }
        }
        return components;
    }
};
