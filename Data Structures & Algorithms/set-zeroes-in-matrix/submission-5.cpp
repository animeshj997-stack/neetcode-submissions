class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int zero=0;
        int m=matrix.size(),n=matrix[0].size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(j!=0 && matrix[i][j]==0){
                    matrix[0][j]=0;
                    matrix[i][0]=0;
                }
                else if(j==0 && matrix[i][j]==0) zero++;
            }
        }

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][0]==0 || matrix[0][j]==0)
                  matrix[i][j]=0;
            }
        }

        if(matrix[0][0]==0){
            for(int j=0;j<n;j++){
                matrix[0][j]=0;
            }
        }
        if(zero){
            for(int i=0;i<m;i++){
                matrix[i][0]=0;
            }
        }

    }
};
