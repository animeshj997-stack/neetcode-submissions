class Solution {
public:
    void dfs(int i, int j, vector<vector<char>> & grid, vector<vector<bool>> &visited, int &n, int &m){
        visited[i][j]=1;
        
        int dx[4] = {-1,1,0,0};
        int dy[4] = {0,0,-1,1};
        for(int k=0;k<4;k++){
            int x=i+dx[k];
            int y=j+dy[k];
            if(x>=0 && y>=0 && x<n && y< m&& grid[x][y]=='1' && visited[x][y]==0)
             dfs(x,y,grid,visited,n,m);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int ans = 0; bool flag=0;
        int n = grid.size(), m= grid[0].size();
     
        vector<vector<bool>> visited(n,vector<bool>(m,0));

        // queue<pair<int,int>> q; 
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1' && visited[i][j]==0){
                    dfs(i,j,grid,visited,n,m);
                    ans++;
                }
            }
        }
        cout<<ans;
        return ans;
    }
};
