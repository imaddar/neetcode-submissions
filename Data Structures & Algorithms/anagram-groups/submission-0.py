class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        # simple solution is just sorting the letters in each word
        # map that takes in a frequency map, returns a list of strings (being the anagrams)
        results = []
        groups = {}
        for s in strs:
            count = [0] * 26
            for c in s:
                i = ord(c) - ord('a')
                count[i] += 1
            key = tuple(count)
            groups.setdefault(key, []).append(s)
        for vals in groups.values():
            results.append(vals)
        return results