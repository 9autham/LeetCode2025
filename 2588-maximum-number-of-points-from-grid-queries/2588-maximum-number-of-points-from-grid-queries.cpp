class Solution {
public:

    struct DSU {
        vector<int> parent;
        vector<int> size;
        DSU(int n) {
            parent.resize(n);
            size.resize(n, 1);
            iota(parent.begin(), parent.end(), 0);
        }

        int find(int v) {
            if (v == parent[v])
                return v;
            return parent[v] = find(parent[v]);
        }

        void unite(int a, int b) {
            a = find(a);
            b = find(b);
            if (a == b) return;

            if (size[b] > size[a]) swap(a, b);
            parent[b] = a;
            size[a] += size[b];
            // size[b] = 0; Unnecessary
        }
    };

    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int k = queries.size();
        vector<pair<int, int>> sortedQueries(k);
        for (int i = 0; i < k; i++)
            sortedQueries[i] = {queries[i], i};
        sort(sortedQueries.begin(), sortedQueries.end());

        int n = grid.size(), m = grid[0].size();
        vector<pair<int, pair<int, int>>> sortedCells(n * m);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                sortedCells[i * m + j] = {grid[i][j], {i, j}};
        sort(sortedCells.begin(), sortedCells.end());

        int i = 0;
        vector<int> ans(k);
        vector<vector<bool>> available(n, vector<bool>(m, false));
        DSU graph(n * m);

        for (int q = 0; q < k; q++) {
            while (i < n * m && sortedCells[i].first < sortedQueries[q].first) {
                int x = sortedCells[i].second.first, y = sortedCells[i].second.second, u = x * m + y;
                available[x][y] = true;
                if (x != 0     && available[x - 1][y]) graph.unite(u, u - m);
                if (y != 0     && available[x][y - 1]) graph.unite(u, u - 1);
                if (x != n - 1 && available[x + 1][y]) graph.unite(u, u + m);
                if (y != m - 1 && available[x][y + 1]) graph.unite(u, u + 1);
                i++;
            }
            if (available[0][0])
                ans[sortedQueries[q].second] = graph.size[graph.find(0)];
            else
                ans[sortedQueries[q].second] = 0;
        }

        return ans;
    }
};

//Revis