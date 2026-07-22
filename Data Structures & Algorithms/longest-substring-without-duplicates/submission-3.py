class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if len(s) == 0:
            return 0
        letters = {s[0]}
        l = r = 0
        longest = 1
        while r < len(s) - 1:
            r += 1
            print(s[r])
            while s[r] in letters:
                letters.remove(s[l])
                l += 1
            longest = max(r - l + 1, longest)
            print(s[l:r+1])
            letters.add(s[r])
        return longest