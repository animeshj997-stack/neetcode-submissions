class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<int>> visited = grid;
        int m = grid.size(),n=grid[0].size();
        int count_fresh = 0;
        queue<pair<int,int>> q;
        for(int row=0;row<m;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==2){
                    q.push({row,col});
                }
                else if(grid[row][col]==1){
                    count_fresh++;
                }
            }
        }
        pair<int,int> directions[] = {{0,1},{0,-1},{1,0},{-1,0}};
        int ans = 0;
        int cnt=0;
        while(count_fresh>0 && !q.empty()){
            int length = q.size();
            for (int i = 0; i < length; i++) {              
                auto pair = q.front();
                int row = pair.first;
                int col = pair.second;
                q.pop();
                for(auto [dx,dy] : directions){
                    int newR = row+dx;
                    int newC = col+dy;
                    
                    if(newR<m && newC<n && newR>=0 && newC>=0 && visited[newR][newC]==1){
                        visited[newR][newC]=2;
                        count_fresh--;
                        q.push({newR,newC});
                    }
                }
                // size--;
            }
            ans++;
        }
        // if(!count_fresh) return 0;
        return (count_fresh) ? -1 : ans;
    }
};
