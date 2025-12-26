class Solution {
public:
    int bestClosingTime(string c) {
        int y=0;
        int n=0;
        string s="";
        for(int i=0;i<c.size();i++){
            if(c[i]=='Y'){
                y++;
                s.push_back('0');
            }
            else{
                n++;
                s.push_back('1');
            }
        }
        int mdx=s.size();
        int cnt=n;
        int ans=n;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='0'){
                s[i]='1';
                cnt++;
            }
            else{
                s[i]='0';
                cnt--;
            }
            if(cnt<ans){
                ans=cnt;
                mdx=i;
            }
            if(cnt==ans){
                cout<<mdx<<" ";
                mdx=min(mdx,i);
            }
        }
        cout<<endl;
        return mdx;
    }
};