class Solution {
public:
    bool dfs(int i, int j, int k, vector<vector<char>> &board, string word, vector<vector<bool>> &visited,int m,int n){
        if(k==word.size()) return 1;

        if(i<0 || i>=m || j<0 || j>=n || visited[i][j] || word[k]!=board[i][j])
          return 0;

        visited[i][j]=1;
        bool res = dfs(i+1,j,k+1,board,word,visited,m,n) ||
                   dfs(i-1,j,k+1,board,word,visited,m,n) ||
                   dfs(i,j+1,k+1,board,word,visited,m,n) ||
                   dfs(i,j-1,k+1,board,word,visited,m,n);

        visited[i][j]=0;

        return res;           
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size(),n=board[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,0));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(dfs(i,j,0,board,word,visited,m,n)){
                    return 1;
                }
            }
        }

        return 0;
    }
};
