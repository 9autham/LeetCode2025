class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int,int>>vp;
        for(int i=0;i<arr.size();i++){
            int xx=arr[i];
            int cnt=0;
            while(xx){
                cnt++;
                xx=xx&(xx-1);
            }
            vp.push_back({cnt,arr[i]});
        }
        vector<int>ans;
        sort(vp.begin(),vp.end());
        for(auto val:vp){
            ans.push_back(val.second);
        }
        return ans;
    }
};