class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int count_fresh=0;

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                else if(grid[i][j]==1){
                    count_fresh++;
                }
            }
        }

        int res=0;
        int dx[]={1,-1,0,0};
        int dy[]={0,0,-1,1};
        while(!q.empty() && count_fresh){
            int s = q.size();
            while(s){
             int i=q.front().first;
             int j=q.front().second;
             q.pop();
             for(int k=0;k<4;k++){
                int ni=i+dx[k];
                int nj=j+dy[k];
                if(ni>=0 && nj>=0 && ni<grid.size() && nj<grid[0].size() && grid[ni][nj]==1){
                    grid[ni][nj]=2;
                    q.push({ni,nj});
                    count_fresh--;
                }
             }
             s--;
            }
            res++; 
        }

        return (count_fresh) ? -1 : res;
    }
};
