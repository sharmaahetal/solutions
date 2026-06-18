class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses , 0);

        for(auto& p : prerequisites){
            int courses = p[0];
            int prereq = p[1];

            adj[prereq].push_back(courses);
            indegree[courses]++;
        }

        queue<int> q;
        for(int i=0 ; i<numCourses ; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        vector<int> ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();

            ans.push_back(node);

            for(int next : adj[node]){
                indegree[next]--;

                if(indegree[next] == 0){
                    q.push(next);
                }
            }
        }
        if(ans.size() != numCourses){
            return {};
        }
        return ans;
    }
};
