class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto i : flights){
            adj[i[0]].push_back({i[1],i[2]});
        }
        vector<int> dist(n+1,1e9);
        dist[src] = 0;
        queue<pair<int,pair<int,int>>> q;
        
        q.push({0,{src,0}});

        while(!q.empty()){
            int node = q.front().second.first;
            int dis = q.front().second.second;
            int stops = q.front().first;
            q.pop();
            if(stops>k) continue;
            for(auto it : adj[node]){
                if(stops<=k && dis+it.second<dist[it.first]){
                    dist[it.first] = min(dist[it.first],dis+it.second);
                    q.push({stops+1,{it.first,dist[it.first]}});
                }
            }
        }

        return (dist[dst]!=1e9) ? dist[dst] : -1;
    }
};
