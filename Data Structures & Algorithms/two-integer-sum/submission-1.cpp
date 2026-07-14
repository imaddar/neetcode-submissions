class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> checks;
        for (int i = 0; i < nums.size(); i++) {
            if (checks.contains(nums[i])) {
                return vector<int>{checks[nums[i]], i};
            }
            checks[target - nums[i]] = i;
        }
    }
};
