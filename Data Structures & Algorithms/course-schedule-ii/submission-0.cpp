class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<int> res;
        vector<vector<int>> adj(n);
        vector<int> indegree(n,0);
        for(auto it : prerequisites){
          adj[it[1]].push_back(it[0]);
          indegree[it[0]]++;
        }
        
        queue<int> q;
        for(int i=0;i<n;i++){
          if(!indegree[i]){
            q.push(i);
          }
        }

        while(!q.empty()){
          int u = q.front();
          q.pop();
          res.push_back(u);
          for(auto v : adj[u]){
            indegree[v]--;
            if(!indegree[v]){
              q.push(v);
            }
          }
        }
      if(res.size()!=n) return {};
        
      return res;
    }
};
