class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        # we start by getting the counts of each element, stored in a hashmap
            # maybe hashtable w array is better for this implementation
        # then we progressively chop off each of the k most frequent
        # easiest/brute force solution is make full frequency hash map
        # then iterate through hash map in descending order, stopping when we've added the k most frequent elements into our results array
        results = []
        # count = [[]] * len(nums)
        count = [[] for i in range(len(nums) + 1)]
        freq = {}
        for num in nums:
            freq[num] = freq.get(num, 0) + 1
        for num in freq:
            count[freq[num]].append(num) #appending to one of the lists seems to append to all of the lists; why does it do that?
        for nums_counts in reversed(count):
            for num in nums_counts:
                results.append(num)
            if len(results) == k:
                return results
        return nums