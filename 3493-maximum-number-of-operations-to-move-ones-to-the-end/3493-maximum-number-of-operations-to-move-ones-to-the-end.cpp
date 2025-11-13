class Solution {
public:
    int maxOperations(string s) {
        s.push_back('1');
        int n=s.size();
        int idx=n-1;
        int ch=idx;
        int cnt=0;
        int sub=0;
        for(int i=0;i<n-1;i++){
            if(s[i]=='1')sub++;
            if(s[i]=='0' and s[i+1]=='1'){
                cnt=cnt+sub;
            }
        }
        return cnt;
    }
};