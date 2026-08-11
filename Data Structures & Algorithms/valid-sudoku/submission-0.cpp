class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<board.size();i++){
            unordered_set<char> s;
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='.')
                 continue;
                if(s.count(board[i][j])){
                    return 0;
                } 
                s.insert(board[i][j]);
            }
        }

        for(int i=0;i<board.size();i++){
            unordered_set<char> s;
            for(int j=0;j<board[0].size();j++){
                if(board[j][i]=='.')
                 continue;
                if(s.count(board[j][i])){
                    return 0;
                } 
                s.insert(board[j][i]);
            }
        }

        for(int squ=0;squ<9;squ++){
            unordered_set<char> s;
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    int r = (squ/3)*3+i;
                    int c = (squ%3)*3+j;
                    if(board[r][c]=='.') continue;
                    if(s.count(board[r][c])) return 0;
                    s.insert(board[r][c]);
                }
            }
        }

        return 1;
    }
};
