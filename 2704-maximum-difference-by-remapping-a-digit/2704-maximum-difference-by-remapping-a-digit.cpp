class Solution {
public:
    int minMaxDifference(int num) {
        string x=to_string(num);
        int idx=-1;
        char digit;
        for(int i=0;i<x.size();i++){
            if(x[i]!='9'){
                idx=i;
                digit=x[i];
                break;
            }
        }
        string y=x;
        if(idx!=-1){
        for(int i=0;i<x.size();i++){
            if(x[i]==digit){
                x[i]='9';
            }
        }
        }
        char gau=y[0];
        for(int i=0;i<x.size();i++){
            if(gau==y[i]){
                y[i]='0';
            }
        }
        int ans=stoi(x);
        int ans2=stoi(y);
        cout<<ans2<<" ";
        return (ans-ans2);
    }
};