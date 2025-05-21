class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        long long int n=matrix.size();
        long long int m=matrix[0].size();
        // cout<<n<<m;
        int a[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                a[i][j]=-1;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]!=0)
                    continue;
                for(int k=0;k<m;k++)
                    a[i][k]=0;
                for(int k=0;k<n;k++)
                    a[k][j]=0;
                // break;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(a[i][j]==0){
                    matrix[i][j]=0;
                }
            }
        }
    }
};