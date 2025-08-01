class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>>ans;
        vector<int>v;
        v.push_back(1);
        ans.push_back(v);
        if(n==1){
            return ans;
        }
        v.push_back(1);
        ans.push_back(v);
        if(n==2){
            return ans;
        }
        n=n-2;
        int k=1;
        while(n){
            vector<int>alpha;
            alpha.push_back(1);
            auto it=ans[k++];
            for(int i=0;i<it.size()-1;i++){
                alpha.push_back(it[i]+it[i+1]);
            }
            alpha.push_back(1);
            ans.push_back(alpha);
            n--;
        }
        return ans;
    }
};