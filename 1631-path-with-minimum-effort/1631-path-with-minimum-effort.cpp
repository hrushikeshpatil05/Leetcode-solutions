class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();

        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;

        pq.push({0, {0, 0}});
        vector<vector<int>> dist(m, vector<int>(n, 1e8));
        dist[0][0] = 0;

        int dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

        while (!pq.empty()) {
            auto [d, top] = pq.top();
            auto [i, j] = top;
            pq.pop();
            if (i == m - 1 && j == n - 1) {
                return d;
            }
            for (int k = 0; k < 4; k++) {
                int nr = i + dir[k][0];
                int nc = j + dir[k][1];
                if (nr >= 0 && nc >= 0 && nr < m && nc < n) {
                    int currDist = max(d, abs(heights[nr][nc] - heights[i][j]));
                    if (d < dist[nr][nc]) {
                        dist[nr][nc] = max(d, currDist);
                        pq.push({dist[nr][nc], {nr, nc}});
                    }
                }
            }
        }
        return 0;
    }
};