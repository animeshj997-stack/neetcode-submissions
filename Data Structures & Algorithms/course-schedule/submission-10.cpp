class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n,0);
        for(auto i : pre){
            adj[i[1]].push_back(i[0]);
            indegree[i[0]]++;
        }

        int count=0;
        queue<int> q;
        for(int i=0;i<n;i++){
            if(!indegree[i])
             q.push(i);
        }

        while(!q.empty()){
            int u = q.front();
            q.pop();
            count++;
            for(auto v : adj[u]){
                indegree[v]--;
                if(!indegree[v]){
                    q.push(v);
                }
            }
        }

        return (count==n);
    }
};
