class Solution {
public:
    void dfs(vector<vector<int>> &adj, int i, vector<int> &indegree, vector<int> &topo, vector<bool> &visited) {
           topo.push_back(i);
           visited[i]=1;
           for(auto j : adj[i]){
            indegree[j]--;
            if(indegree[j]==0 && !visited[j]){
                dfs(adj,j,indegree,topo, visited);
            }
           }
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> adj(n);
        vector<int> indegree(n,0);
        vector<int> topo;
        vector<bool> visited(n,0);
        for(auto it : prerequisites){
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }
  
        for(int i=0;i<n;i++){
            if(!indegree[i] && !visited[i])
             dfs(adj,i,indegree,topo,visited);
        } 
        cout<<topo.size();
        return (topo.size() == n);     
    }
};
