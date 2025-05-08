#define State pair<int, pair<int, pair<int, bool>>>

class Solution {
public:

    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();

        priority_queue<State, vector<State>, greater<State>> pq;

        vector<vector<int>> minTime(n, vector<int>(m, INT_MAX));

        pq.push({0, {0, {0, true}}});
        minTime[0][0] = 0;

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        while (!pq.empty()) {
            auto state = pq.top();
            pq.pop();

            int curTime = state.first;
            int i = state.second.first;
            int j = state.second.second.first;
            bool isEven = state.second.second.second;

            if (i == n - 1 && j == m - 1) return curTime;

            for (int k = 0; k < 4; k++) {
                int ni = i + dx[k];
                int nj = j + dy[k];

                if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                    int nextMoveTime = isEven ? 1 : 2;
                    int waitTime = max(0, moveTime[ni][nj] - curTime);
                    int newTime = curTime + nextMoveTime + waitTime;

                    if (newTime < minTime[ni][nj]) {
                        minTime[ni][nj] = newTime;
                        pq.push({newTime, {ni, {nj, !isEven}}});
                    }
                }
            }
        }

        return -1;
    }
};
