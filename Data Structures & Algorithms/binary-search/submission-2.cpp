class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size();
        int midpoint;
        while (l < r) {
            midpoint = (l + r) / 2;
            if (target == nums[midpoint]) {
                return midpoint;
            }
            else if (target < nums[midpoint]) {
                r = midpoint;
            }
            else {
                l = midpoint + 1;
            }
        }
        return -1;
    }
};
