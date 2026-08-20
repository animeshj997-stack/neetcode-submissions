class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n);

        for(auto i : pre){
            adj[i[1]].push_back(i[0]);
            indegree[i[0]]++;
        }

        queue<int> q;
        for(int i=0;i<n;i++){
            if(!indegree[i]){
                q.push(i);
            }
        }
        
        int cnt=0;

        while(!q.empty()){
            int v=q.front();
            q.pop();
            cnt++;
            for(auto u : adj[v]){
                indegree[u]--;
                if(!indegree[u]){
                    q.push(u);
                }
            }
        }

        return (cnt==n);
    }
};
