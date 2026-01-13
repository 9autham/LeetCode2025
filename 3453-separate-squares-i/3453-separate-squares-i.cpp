class Solution {
public:
    double computeArea(vector<vector<int>>& squares, double y) {
        double above = 0, below = 0;
        
        for (auto& square : squares) {
            int x = square[0], yBottom = square[1], side = square[2];
            int yTop = yBottom + side;
            long long totalArea = (long long)side * side; 

            if (yTop <= y) {
                below += (double)totalArea;
            } else if (yBottom >= y) {
                above += (double)totalArea;
            } else {
                double abovePart = yTop - y;
                double belowPart = y - yBottom;
                above += abovePart * side;
                below += belowPart * side;
            }
        }
        return above - below;
    }

    double separateSquares(vector<vector<int>>& squares) {
        vector<int> yValues;
        for (auto& square : squares) {
            yValues.push_back(square[1]);
            yValues.push_back(square[1] + square[2]);
        }

        sort(yValues.begin(), yValues.end());
        yValues.erase(unique(yValues.begin(), yValues.end()), yValues.end());

        double left = yValues.front(), right = yValues.back();
        while (right - left > 1e-6) {
            double mid = (left + right) / 2.0;
            if (computeArea(squares, mid) > 0) {
                left = mid;
            } else {
                right = mid;
            }
        }
        return (left + right) / 2.0;
    }
};
