#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int n = bottomLeft.size();
        long long max_area = 0;
        
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int x_overlap = max(0, min(topRight[i][0], topRight[j][0]) - max(bottomLeft[i][0], bottomLeft[j][0]));
                int y_overlap = max(0, min(topRight[i][1], topRight[j][1]) - max(bottomLeft[i][1], bottomLeft[j][1]));
                int side_length = min(x_overlap, y_overlap);
                max_area = max(max_area, (long long)side_length * side_length);
            }
        }
        
        return max_area;
    }
};
