class Solution:
    def minWindow(self, s: str, t: str) -> str:
        if t == "":
            return ""
        
        d1, d2 = {}, {}
        for c in t:
            d1[c] = 1 + d1.get(c, 0)
        
        have, need = 0, len(d1)
        min_substr, shortest = [-1, -1], float("infinity")
        l = 0
        for r in range(len(s)):
            
            d2[s[r]] = 1 + d2.get(s[r], 0)
        
            if s[r] in d1 and d2[s[r]] == d1[s[r]]:
                have += 1

            while have == need:
                if (r - l + 1) < shortest:
                    min_substr = [l, r]
                    shortest = r - l + 1

                d2[s[l]] -= 1
                if s[l] in d1 and d2[s[l]] < d1[s[l]]:
                    have -= 1
                l += 1
        l, r = min_substr
        return s[l : r + 1] if shortest != float("infinity") else ""