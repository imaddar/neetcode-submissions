class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        vector<int> results = vector<int>(nums.size(), 1);
        results[0] = 1;
        int prefix = 1;

        for (int i = 1; i < nums.size(); i++) {
            results[i] *= nums[i-1] * prefix;
            prefix *= nums[i-1];
        }
        int postfix = 1;
        for (int i = nums.size() - 2; i >= 0; i--) {
            results[i] *= nums[i+1] * postfix;
            postfix *= nums[i+1];
        }
        return results;
    }
};
