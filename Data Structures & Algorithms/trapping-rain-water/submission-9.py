class Solution:
    def trap(self, height: List[int]) -> int:
        total = 0
        # water only fits between a decrease followed by an increase (in height)
        # total water that can be trapped at a specific position
        # we look at both sides until the height starts decreasing
        curr = 0
        # min(height[left], height[right]) - height[curr]
        for curr in range(1, len(height) - 1):
            max_l = max(height[0:curr])
            max_r = max(height[curr:])
            print(max_l, height[curr], max_r)
            total += max(min(max_l, max_r) - height[curr], 0)
        return total