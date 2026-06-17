class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
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
        int completed = 0;
        while(!q.empty()){
            int curr = q.front();
            q.pop();

            completed++;

            for(int ngbr : adj[curr]){
                indegree[ngbr]--;

                if(indegree[ngbr] == 0){
                    q.push(ngbr);
                }
            }
        }
        return completed == numCourses;
    }
};
