class Solution {
public:
    int minDominoRotations(vector<int>& top, vector<int>& bottom) {
        int t=top[0];
        int b=bottom[0];
        int t1=0,b1=0;
        int t2=0,b2=0;
        bool pp=true,pb=true;
        for(int i=0;i<top.size();i++)
        {
            if(top[i]!=t&&bottom[i]!=t) pp=false;
            if(top[i]!=b&&bottom[i]!=b) pb=false;
            if(top[i]==t) t1++;
            if(bottom[i]==t) b1++;
            if(top[i]==b) t2++;
            if(bottom[i]==b) b2++;
        }
        if(!pp&&!pb) return -1;
        int res=INT_MAX,n=top.size();
        if(pp) res=min(res,min(n-t1,n-b1));
        if(pb) res=min(res,min(n-t2,n-b2));
        return res;
    }
};