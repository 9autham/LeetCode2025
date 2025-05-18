class Solution {
    vector<string> ways;
    string s;
    vector<char> col = {'R', 'G', 'B'};
    int md = 1e9 + 7;
    int dp[50][1001];
public:
    void genWays(int n){
        if(s.size() == n){
            ways.push_back(s);
            return;
        }
        for(char c: col){
            if(s.empty() || s.back()!=c){
                s.push_back(c);
                genWays(n);
                s.pop_back();
            }
        }
    }
    bool isValid(string &a, string &b){
        for(int i=0;i<a.size();i++){
            if(a[i]==b[i])return false;
        }
        return true;
    }
    int dfs(int prev, int n){
        if(n==0)return 1;
        if(dp[prev][n]!=-1)return dp[prev][n];
        long long res = 0;
        for(int i=0;i<ways.size();i++){
            if(prev==ways.size() || (prev !=i and isValid(ways[prev], ways[i]))){
                long long temp = dfs(i, n-1)%md;
                res += temp;
                res %= md;
            }
        }
        return dp[prev][n] = res;
    }
    int colorTheGrid(int m, int n) {
        genWays(m);
        memset(dp, -1, sizeof(dp));
        long long res = dfs(ways.size(), n);
        return res;
    }
};//Revisit
