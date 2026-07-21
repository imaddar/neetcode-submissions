class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0
        nums = set(nums)
        length = 1
        max_length = length
        start = 0
        for num in nums:
            if num - 1 in nums:
                continue
            else:
                start = num
                length = 1
                while start + 1 in nums:
                    length += 1
                    start = start + 1
                    if length > max_length:
                        max_length = length
                    
        return max_length