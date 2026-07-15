class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==0){
                    q.push({i,j});
                }
            }
        }
        
        vector<pair<int,int>> dir={{-1,0}, {1,0}, {0,1}, {0,-1}};
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            for(auto [di,dj] : dir){
                int ni=i+di, nj=j+dj;
                if(ni>=0 && nj>=0 && ni<grid.size() && nj<grid[0].size() && grid[ni][nj]==INT_MAX){
                    grid[ni][nj] = 1+grid[i][j];
                    q.push({ni,nj});
                }
            }
        }
    }
};
