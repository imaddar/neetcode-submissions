class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        stack<double> s;
        vector<pair<int,double>> pos_and_time;
        for (int i = 0; i < position.size(); i++) {
            pair<int,double> p = {position[i], (static_cast<double>(target - position[i])) / speed[i]};
            pos_and_time.push_back(p);
        }

        sort(pos_and_time.begin(), pos_and_time.end());

        for (int i = pos_and_time.size() - 1; i >= 0; i--) {
            if (s.empty()) {
                s.push(pos_and_time[i].second);
            }
            else if (pos_and_time[i].second > s.top()) {
                s.push(pos_and_time[i].second);
            }
        }
        return s.size();
    }
};
