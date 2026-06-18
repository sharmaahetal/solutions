class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);    //build a graph
        vector<int> indegree(numCourses , 0);

        for(auto& p : prerequisites){      //compute indegree
            int courses = p[0];
            int prereq = p[1];

            adj[prereq].push_back(courses);
            indegree[courses]++;
        }
        queue<int> q;       //push nodes in queue if(indegree = 0)
        for(int i=0 ; i<numCourses ; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        vector<int> ans;
        while(!q.empty()){      //take node from queue
            int node = q.front();
            q.pop();

            ans.push_back(node);    //add to answer

            for(int ngbr : adj[node]){
                indegree[ngbr]--;   //decrease indegree of neighbors

                if(indegree[ngbr] == 0){
                    q.push(ngbr);       //if ngbr indegree = 0 , push it
                }
            }
        }
        if(ans.size() != numCourses){
            return {};      // if no possible order , return {}
        }
        return ans;
    }
};
