class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.size();
        vector<int>a(n);
        vector<int>b(n);
        int ac=0;
        int bc=0;
        for(int i=0;i<n;i++){
            if(s[i]=='b'){
                bc++;
            }
            b[i]=bc;
        }
        for(int i=n-1;i>=0;i--){
            if(s[i]=='a'){
                ac++;
            }
            a[i]=ac;
        }
        int mini=INT_MAX;
        for(int i=n-1;i>=0;i--){
            mini=min(mini,a[i]-1+b[i]);
        }
        if(mini==INT_MAX)mini=0;
        return mini;
    }
};