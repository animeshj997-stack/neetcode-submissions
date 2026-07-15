class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int res=0;
        int count_fresh=0;
        queue<pair<int,int>> q;
        int m = grid.size(), n = grid[0].size();

        for(int i = 0; i < m ; i++){
            for(int j = 0; j < n ; j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                else if(grid[i][j]==1){
                    count_fresh++;
                }
            }
        }
        if(count_fresh==0) return 0;
        if(q.empty()) return -1;
        
        int di[] = {1,-1,0,0};
        int dj[] = {0,0,1,-1};
        while(!q.empty()){
            int size = q.size();
            while(size){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                for(int k=0;k<4;k++){
                    int ni=i+di[k];
                    int nj=j+dj[k];
                    if(ni>=0 && nj>=0 && ni<m && nj<n && grid[ni][nj]==1){
                        grid[ni][nj]=2;
                        q.push({ni,nj});
                        count_fresh--;
                    }
                }
                size--;
            }
            res++;
        }   
        
        if(count_fresh==0)
        return res-1; 
        return -1;
    }
};
