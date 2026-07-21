class Solution:
    def maxArea(self, heights: List[int]) -> int:
        # for a given container, it is the height of the smaller side * 
        max_water = 0
        l, r = 0, len(heights) - 1
        while l < r:
            max_water = max((r - l) * min(heights[r], heights[l]), max_water)
            if heights[l] < heights[r]:
                l += 1
            else:
                r -= 1
        return max_water