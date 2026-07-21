class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        # naive way is to sort
        if len(nums) == 0: 
                return 0
        length = 1
        max_length = 1
        nums_sorted = sorted(nums)
        for i in range(len(nums_sorted) - 1):
            if (nums_sorted[i + 1] - nums_sorted[i]) == 1:
                length += 1
                if(length > max_length):
                    max_length = length
            elif (nums_sorted[i + 1]) == nums_sorted[i]:
                continue
            else:
                length = 1
        return max_length