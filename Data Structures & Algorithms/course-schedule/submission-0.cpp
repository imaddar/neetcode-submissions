class Solution {
    map<int, vector<int>> pq = {};
    set<int> visited;

public:

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        for (int i = 0; i < numCourses; i++) {
            pq[i] = {};
        }

        for (const auto& prereq : prerequisites) {
            pq[prereq[1]].push_back(prereq[0]);
        }

        for (int c = 0; c < numCourses; c++) {
            if (!dfs(c)) {
                return false;
            }
        }
        

        return true;
    }

    bool dfs(int crs) {
        if (visited.contains(crs)) {
            return false;
        }

        if (pq[crs].empty()) {
            return true;
        }

        visited.insert(crs);
        for (int pre : pq[crs]) {
            if (!dfs(pre)) {
                return false;
            }
        }

        visited.erase(crs);
        pq[crs].clear();
        return true;


    }
};
