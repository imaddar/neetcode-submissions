class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        // loop through the grid until we get to a 1 (start of island)
        // we dfs through the island until we get to a point of water
        // to mark an island point as seen, we change 1 to 0
        // once our dfs terminates, we increase our island counter

        // we are getting no increments
        // what are the failure modes
        // 
        int numIslands = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == '1') {
                    dfs(i, j, grid);
                    numIslands += 1;
                }
            }
        }
        return numIslands;
    }

    void dfs(int x, int y, vector<vector<char>>& grid) {
        if (grid[x][y] == '1') {
            grid[x][y] = '0';
            if (x + 1 < grid.size()) {
                dfs(x + 1, y, grid);
            }
            if (x - 1 >= 0) {
                dfs(x - 1, y, grid);
            }
            if (y + 1 < grid[0].size()) {
                dfs(x, y + 1, grid);
            }
            if (y - 1 >= 0) {
                dfs(x, y - 1, grid);
            }
        }
    }
};
