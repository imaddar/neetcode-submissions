class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int area;
        int maxArea = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) {
                    area = dfs(i, j, grid);
                    maxArea = max(area, maxArea);
                }
            }
        }
        return maxArea;
    }

    int dfs(int x, int y, vector<vector<int>>& grid) {
        int area = 1;
        if (grid[x][y] == 0) {
            return 0;
        } else {
            grid[x][y] = 0;
            if (x + 1 < grid.size()) {
                area += dfs(x + 1, y, grid);
            }
            if (x - 1 >= 0) {
                area += dfs(x - 1, y, grid);
            }
            if (y + 1 < grid[0].size()) {
                area += dfs(x, y + 1, grid);
            }
            if (y - 1 >= 0) {
                area += dfs(x, y - 1, grid);
            }

            return area;
        }

    }
};
