class Solution {
public:
    void dfs(vector<vector<int>> &adj, int i, vector<int> &indegree, vector<int> &topo, vector<bool> &visited) {
           visited[i]=1;
           for(auto j : adj[i]){
            if(!visited[j]){
                indegree[j] = indegree[i];
                dfs(adj,j,indegree,topo, visited);
            }
           }
           topo.push_back(i);
    }
    bool canFinish(int n, vector<vector<int>>& pre) {
      vector<int> indegree(n,0); 
      vector<vector<int>> adj(n);
      for(auto it : pre){
        adj[it[1]].push_back(it[0]);
        indegree[it[0]]++;
      }

      queue<int> q;
      for(int i=0;i<n;i++){
        if(!indegree[i]) q.push(i);
      }

      int num=0;
      while(!q.empty()){
        int u = q.front();
        num++;
        q.pop();
        for(auto i : adj[u]){
            indegree[i]--;
            if(indegree[i]==0){
                q.push(i);
            }
        }
      }

      return (num==n);
    }
};
