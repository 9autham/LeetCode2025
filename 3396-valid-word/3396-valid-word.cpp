class Solution {
public:
    bool isValid(string s) {
        int n=s.size();
        
        if(n<3)return false;
        int cnt1=0;
        int cnt2=0;
        int cnt3=0;
        for(int i=0;i<n;i++){
            if((s[i]>='a' and s[i]<='z') or (s[i]>='A' and s[i]<='Z') or (s[i]>='0' and s[i]<='9')){
                cnt1++;
            }
            else{
                return false;
            }
            if(s[i]=='A' or s[i]=='E' or s[i]=='I' or s[i]=='O' or s[i]=='U' or s[i]=='a' or s[i]=='e' or s[i]=='i' or s[i]=='o' or s[i]=='u'){
                cnt2++;
            }
            else if(!(s[i]>='0' and s[i]<='9')){
                cnt3++;
            }
        }
        cout<<cnt1<<" "<<cnt2<<" "<<cnt3<<endl;
        return (cnt1 and cnt2 and cnt3);
    }
};