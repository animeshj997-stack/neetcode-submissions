class Solution {
public:
    int m, n;
    bool dfs(int i, int j, int k, vector<vector<char>> &board, string word){
        if(k==word.size()) return 1;

        if(i<0 || i>=m || j<0 || j>=n || board[i][j]=='#' || word[k]!=board[i][j])
          return 0;

        // visited[i][j]=1;
        board[i][j]='#';
        bool res = dfs(i+1,j,k+1,board,word) ||
                   dfs(i-1,j,k+1,board,word) ||
                   dfs(i,j+1,k+1,board,word) ||
                   dfs(i,j-1,k+1,board,word);

        // visited[i][j]=0;
        board[i][j]=word[k];

        return res;           
    }
    bool exist(vector<vector<char>>& board, string word) {
        m=board.size(),n=board[0].size();
        // vector<vector<bool>> visited(m,vector<bool>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(dfs(i,j,0,board,word)){
                    return 1;
                }
            }
        }

        return 0;
    }
};
