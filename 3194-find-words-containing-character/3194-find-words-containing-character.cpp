class Solution {
public:
    bool f(string &s,char x){
        for(auto it:s){
            if(it==x)return true;
        }
        return false;
    }
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int>ans;
        int cnt=0;
        for(auto it:words){
            if(f(it,x))
                ans.push_back(cnt);
            cnt++;
        }
        return ans;
    }
};