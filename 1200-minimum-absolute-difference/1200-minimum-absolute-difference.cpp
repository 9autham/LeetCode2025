class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>&arr) {
        vector<vector<int>>v;
        map<int,int>m;
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i++)
            m[arr[i]]++;
        int md=INT_MAX;
        for(int i=0;i<arr.size()-1;i++){
            md=min(md,abs(arr[i]-arr[i+1]));
        }
        for(int i=0;i<arr.size();i++){
            if(m[arr[i]+md]){
                vector<int>k;
                k.push_back(arr[i]);
                k.push_back(arr[i]+md);
                v.push_back(k);
            }
        }
        return v;
    }
};