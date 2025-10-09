class Solution {
public:
    long long minTime(vector<int>&sk, vector<int>&mn) {
        vector<long long>v(sk.size()+1,0);
        int n=mn.size(),i,k,j,x=sk.size();
        for(i=1;i<=x;i++)
            v[i]=v[i-1]+mn[0]*sk[i-1];

        for(i=1;i<n;i++){
            long long cal=v[x];
            for(j=x-2;j>=0;j--){
                cal=cal-(mn[i]*sk[j]);
                cal = max(cal,v[j+1]);
            }
            v[0]=cal;
            for(k=1;k<=x;k++)
                v[k]=v[k-1]+mn[i]*sk[k-1];
        }
        return v[x];
    }
};