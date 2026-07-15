class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& p) {
        int n = numCourses;
        vector<vector<int>> adj(n);
        vector<int> indegree(n,0);
        // vector<int> visited(n,0);
        vector<int> topo;
        for(auto it : p){
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }

        queue<int> q;
        for(int i=0;i<n;i++)
          if(indegree[i]==0) q.push(i);

        while(!q.empty()){
             int node = q.front();
            //  visited[node] = 1;
             topo.push_back(node);
             q.pop();
             for(auto i : adj[node]){
                indegree[i]--;
                if(indegree[i]==0)
                 q.push(i);
             }
        }

        return topo.size()==n; 
    }
};
