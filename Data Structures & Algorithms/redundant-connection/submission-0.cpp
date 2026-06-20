class Solution {
public:
    vector<int> parent;

    int find(int node){
        if(parent[node] == node){
            return node;
        }
        return find(parent[node]);
    }

    void Union(int a , int b){
        
        int pa = find(a);
        int pb = find(b);

        parent[pb] = pa;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n+1);
        for(int i=0 ; i<= n ; i++){
            parent[i] = i;
        }
        for(auto& e : edges){
            int u = e[0];
            int v = e[1];

            if(find(u) == find(v)){
                return {u , v};
            }
            Union(u,v);
        }
        return {};
    }
};
