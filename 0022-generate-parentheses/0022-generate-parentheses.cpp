class Solution {
public:
    void solve(vector<string>&ans,int ob,int cb,string s,int n){
        if(s.size()==2*n){
            ans.push_back(s);
        }
        if(ob<n){
            solve(ans,ob+1,cb,s+"(",n);
        }
        if(ob>cb)
        solve(ans,ob,cb+1,s+")",n);
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        solve(ans,0,0,"",n);
        return ans;
    }
};