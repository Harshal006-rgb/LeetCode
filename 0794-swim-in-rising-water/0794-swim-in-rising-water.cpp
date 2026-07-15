class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        priority_queue<pair<int, pair<int, int>> , vector<pair<int, pair<int, int>>> , greater<pair<int, pair<int, int>>>> pq;

        vector<vector<int>> vis(n, vector<int>(n, 0));

        pq.push({grid[0][0], {0, 0}});
        vis[0][0] = 1;

        vector<int> erow = {0, 0, -1, 1};
        vector<int> ecol = {-1, 1, 0, 0};

        while (!pq.empty()) {
            auto it = pq.top();
            int time = it.first;
            int row = it.second.first;
            int col = it.second.second;
            pq.pop();

            if (row == n - 1 && col == n - 1) {
                return time;
            }

            for (int i = 0; i < 4; i++) {
                int nrow = row + erow[i];
                int ncol = col + ecol[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && !vis[nrow][ncol]) {
                    vis[nrow][ncol] = 1;
                    pq.push({max(time, grid[nrow][ncol]), {nrow, ncol}});
                }
            }
        }

        return -1;
    }
};