class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        # we start by getting the counts of each element, stored in a hashmap
            # maybe hashtable w array is better for this implementation
        # then we progressively chop off each of the k most frequent
        # easiest/brute force solution is make full frequency hash map
        # then iterate through hash map in descending order, stopping when we've added the k most frequent elements into our results array
        results = []
        freq = {}
        for num in nums:
            freq[num] = freq.get(num, 0) + 1
        for key, value in sorted(freq.items(), key=lambda x: x[1], reverse=True):
            results.append(key)
            if len(results) == k:
                return results
        return results