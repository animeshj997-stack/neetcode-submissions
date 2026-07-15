class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // unordered_set<int> row,col;
        int m = matrix.size(), n = matrix[0].size();

        // for(int i=0;i<matrix.size();i++){
        //     for(int j=0;j<matrix[0].size();j++){
        //         if(matrix[i][j]==0){
        //             row.insert(i);
        //             col.insert(j);
        //         }
        //     }
        // }

        // for(int i = 0;i<m;i++){
        //     for(int j = 0;j<n;j++){
        //         if(row.count(i) || col.count(j))
        //          matrix[i][j]=0;
        //     }
        // }

        int col_1=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0 && j!=0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
                if(matrix[i][j]==0 && j==0){
                    col_1=1;
                }
            }
        }

           for (int r = 1; r < m; r++) {
            for (int c = 1; c < n; c++) {
                if (matrix[0][c] == 0 || matrix[r][0] == 0) {
                    matrix[r][c] = 0;
                }
            }
        }

        if (matrix[0][0] == 0) {
            for (int c = 0; c < n; c++) {
                matrix[0][c] = 0;
            }
        }

        if (col_1) {
            for (int r = 0; r < m; r++) {
                matrix[r][0] = 0;
            }
        }

    }
};
