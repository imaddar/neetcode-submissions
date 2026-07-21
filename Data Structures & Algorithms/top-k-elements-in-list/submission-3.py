class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        results = []
        count = [[] for i in range(len(nums) + 1)]
        freq = {}
        for num in nums:
            freq[num] = freq.get(num, 0) + 1
        for num in freq:
            count[freq[num]].append(num)

        for nums_counts in reversed(count):
            for num in nums_counts:
                results.append(num)
            if len(results) == k:
                return results