class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int time=0;
        for(int i=0; i<points.size()-1; i++){
            while((points[i][0] != points[i+1][0]) && (points[i][1] != points[i+1][1])){
                points[i][0] += (points[i+1][0] > points[i][0]) ? 1:-1;
                points[i][1] += (points[i+1][1] > points[i][1]) ? 1:-1;
                time++;
            }
            if(points[i][1] == points[i+1][1]){
                time += abs(points[i][0] - points[i+1][0]);
            } else {
                time += abs(points[i][1] - points[i+1][1]);
            }
        }
        return time;
    }
};