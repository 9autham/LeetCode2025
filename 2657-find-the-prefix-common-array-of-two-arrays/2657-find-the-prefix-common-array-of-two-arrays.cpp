class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        vector<int>ans;
        map<int,int>m;
        for(int i=0;i<n;i++){
            m[A[i]]++;
            int cnt=0;
            for(int j=0;j<=i;j++){
                if(m[B[j]]){
                    cnt++;
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};