#define MOD (int)1000000007
#define ll long long 
int modM(int n, int m) { return ((ll)(n % MOD) * (m % MOD)) % MOD; }
class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& h, vector<int>& v) {
        unordered_map<int,int>mp;
        h.push_back(m);
        reverse(h.begin(),h.end());
        h.push_back(1);
        reverse(h.begin(),h.end());
        int nh=h.size();
        for(int i=0;i<nh;i++){
            for(int j=i+1;j<nh;j++){
                int xx=abs(h[i]-h[j]);
                if(mp[xx]==0){
                    mp[xx]++;
                }
            }
        }
        int maxi=-1;
        v.push_back(n);
        reverse(v.begin(),v.end());
        v.push_back(1);
        reverse(v.begin(),v.end());
        int nv=v.size();
        for(int i=0;i<nv;i++){
            for(int j=i+1;j<nv;j++){
                int xx=abs(v[i]-v[j]);
                if(mp[xx]==1){
                    maxi=max(maxi,xx);
                }
            }
        }
//         int xx=h[0]-1;
//         mp[xx]++;
//         for(int i=1;i<nh;i++){
//             xx=h[i]-h[i-1];
//             if(mp[xx]==0){
//                 mp[xx]++;
//             }
//         }
//         int yy=m-h[nh-1];
//         if(mp[yy]==0){
//             mp[yy]++;
//         }
        
//         xx=v[0]-1;
//         if(mp[xx]==1){
//             mp[xx]++;
//         }
//         for(int i=1;i<nv;i++){
//             xx=v[i]-v[i-1];
//             if(mp[xx]==1){
//                 mp[xx]++;
//             }
//         }
//         yy=n-v[nv-1];
//         if(mp[yy]==1){
//             mp[yy]++;
//         }
        int ans=-1;
        if(maxi>0){
            ans=modM(maxi,maxi);
        }
        return ans;
    }
};