class Solution:
    def trap(self, height: List[int]) -> int:
        left_max = [0] * len(height)
        right_max = [0] * len(height)
        curr_max = 0
        for i in range(len(height)):
            curr_max = max(height[i], curr_max)
            left_max[i] = curr_max
        
        curr_max = 0
        for i in range(len(height) - 1, -1, -1):
            curr_max = max(height[i], curr_max)
            right_max[i] = curr_max

        total = 0
        for i in range(1, len(height) - 1):
            total += max(min(left_max[i], right_max[i]) - height[i], 0)

        return total