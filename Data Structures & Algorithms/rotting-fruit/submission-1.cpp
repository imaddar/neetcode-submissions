class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        // start by first pass finding rotten fruit
        // loop through each, build out first layer of BFS
        // does it matter if its in the same queue?

        // repeat bfs until stopping condition (queue is empty? or no neighbors are added?) adding neighbor to a list is the rotting process
        // after bfs stops, give pass to see if any fruits remain fresh
        // if so, return -1, otherwise return timestep counter
        queue<vector<int>> rotten = {};
        queue<vector<int>> rotting = {};
        int timeElapsed = 0;
        
        // first pass, add initial rotten fruits
        for(int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 2) {
                    timeElapsed = -1;
                    rotten.push({i,j});
                }
            }
        }


        while(!rotten.empty()) {
            auto cell = rotten.front();
            int i = cell[0], j = cell[1];

            if (i + 1 < grid.size() && grid[i+1][j] == 1) {
                grid[i+1][j] = 2;
                rotting.push({i+1,j});
            }
            if (i - 1 >= 0 && grid[i-1][j] == 1) {
                grid[i-1][j] = 2;
                rotting.push({i-1,j});
            }
            if (j + 1 < grid[i].size() && grid[i][j+1] == 1) {
                grid[i][j+1] = 2;
                rotting.push({i,j+1});
            }
            if (j - 1 >= 0 && grid[i][j-1] == 1) {
                grid[i][j-1] = 2;
                rotting.push({i,j-1});
            }

            rotten.pop();
            if(rotten.empty()) {
                rotten = rotting;
                rotting = {};
                timeElapsed++;
            }
        }

        for(int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }

        return timeElapsed;
    }
};
