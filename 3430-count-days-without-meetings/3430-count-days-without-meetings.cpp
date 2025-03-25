class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        int x=intervals[0][0];
        int y=intervals[0][1];
        for(int i=1;i<n;i++){
            if((x<=intervals[i][0] and y>=intervals[i][0]) or (x<=intervals[i][0] and y>=intervals[i][1])){
                x=min(x,intervals[i][0]);
                y=max(y,intervals[i][1]);
            }
            else{
                vector<int>v(2);
                v[0]=x;
                v[1]=y;
                ans.push_back(v);
                x=intervals[i][0];
                y=intervals[i][1];
            }
        }
        vector<int>v(2);
                v[0]=x;
                v[1]=y;
                ans.push_back(v);
                return ans;
    }
    int countDays(int days, vector<vector<int>>& meetings) {
        vector<vector<int>>in=merge(meetings);
        int cnt=0;
        for(int i=0;i<in.size();i++){
            cnt=cnt+(in[i][1]-in[i][0])+1;
        }
        return days-cnt;
    }
};