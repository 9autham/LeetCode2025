class Solution {
public:
    int M = 1e9 + 7;
    int n = 26;
    vector <vector <int>> multiply(vector <vector <int>>& A, vector <vector<int>>& B){
        vector <vector <int>> product(n, vector <int> (n, 0));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                for(int k = 0; k < n; k++){
                    product[i][j] = (product[i][j] + (1LL*(A[i][k])*(B[k][j]) % M)) % M;
                }
            }
        }

        return product;
    }

    vector <vector <int>> binExp(vector <vector<int>> T, int t){
        vector <vector <int>> res(n, vector <int> (n, 0));
        for(int i = 0; i < n; i++) res[i][i] = 1;

        while(t > 0){
            if(t & 1){
                res = multiply(res, T);
            }

            t >>= 1;
            T = multiply(T, T);
        }

        return res;
    }

    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        vector <int> freq(n, 0);
        for(char c: s) freq[c-'a']++;

        vector <vector<int>> T(n, vector <int> (n, 0));
        for(int i = 0; i < n; i++){
            for(int j = 1; j <= nums[i]; j++){
                T[(i+j) % n][i]++; 
            }
        }

        T =  binExp(T, t);

        int len = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                len = (len + ((1LL * freq[i] * T[j][i]) % M)) % M;
            }
        }

        return len;
    }
};