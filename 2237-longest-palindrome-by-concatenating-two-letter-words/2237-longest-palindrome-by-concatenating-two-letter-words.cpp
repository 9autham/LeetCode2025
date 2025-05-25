class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string,int>m;
        map<string,int>m2;
        int n=words.size();
        int maxi=0;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(words[i][0]==words[i][1]){
                m2[words[i]]++;
            }
            else{
                m[words[i]]++;
            }
        }
        int cnt1=0;
        for(auto val:m2){
            if(val.second%2){
                cnt1=2;
                cnt=cnt+((val.second/2)*4);
            }
            else
            cnt=cnt+(val.second*2);
        }
        for(auto val:m){
            string s=val.first;
            int x=val.second;
            reverse(s.begin(),s.end());
            int y=m[s];
            cnt=cnt+(min(x,y)*2);
            // cout<<cnt<<" ";
        }
        return (cnt+maxi+cnt1);
    }
};