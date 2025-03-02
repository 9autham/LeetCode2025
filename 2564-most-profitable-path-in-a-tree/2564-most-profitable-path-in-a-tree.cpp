#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:
    // DFS to determine when Bob reaches each node
    bool findBobPath(int node, vector<int>& visited, vector<vector<int>>& graph, vector<int>& bobTime, int time) {
        if (node == 0) return true;  // If Bob reaches the root, return true
        
        visited[node] = 1;
        
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                bool reached = findBobPath(neighbor, visited, graph, bobTime, time + 1);
                if (reached) {
                    bobTime[neighbor] = time + 1;  // Store Bob's arrival time
                    return true;
                }
            }
        }
        return false;
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        vector<vector<int>> graph(n);

        // Construct adjacency list
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        // Step 1: Compute when Bob reaches each node
        vector<int> visited(n, 0);
        vector<int> bobTime(n, INT_MAX);  // Initialize to a large value
        bobTime[bob] = 0;
        findBobPath(bob, visited, graph, bobTime, 0);

        // Step 2: Alice's BFS traversal
        queue<pair<int, pair<int, int>>> bfsQueue;  // {node, {time, profit}}
        fill(visited.begin(), visited.end(), 0);
        
        bfsQueue.push({0, {0, amount[0]}});  // Start from root with initial profit
        visited[0] = 1;
        
        int maxProfit = INT_MIN;

        while (!bfsQueue.empty()) {
            int queueSize = bfsQueue.size();
            
            for (int i = 0; i < queueSize; i++) {
                auto [currentNode, data] = bfsQueue.front();
                bfsQueue.pop();
                int elapsedTime = data.first, profit = data.second;

                // If it's a leaf node (excluding the root), update the maximum profit
                if (graph[currentNode].size() == 1 && currentNode != 0) {
                    maxProfit = max(maxProfit, profit);
                }

                // Explore neighbors
                for (int neighbor : graph[currentNode]) {
                    if (visited[neighbor]) continue;

                    visited[neighbor] = 1;
                    int newProfit = profit;

                    if (bobTime[neighbor] > elapsedTime + 1 || bobTime[neighbor] == INT_MAX) {
                        newProfit += amount[neighbor];  // Alice collects full amount
                    } else if (bobTime[neighbor] == elapsedTime + 1) {
                        newProfit += amount[neighbor] / 2;  // Alice shares with Bob
                    }

                    bfsQueue.push({neighbor, {elapsedTime + 1, newProfit}});
                }
            }
        }

        return maxProfit;
    }
};
