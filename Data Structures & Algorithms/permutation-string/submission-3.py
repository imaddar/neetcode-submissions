class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        d1 = [0] * 26
        d2 = [0] * 26
        l = 0
        if len(s1) > len(s2):
            return False
        for c in range(len(s1)):
            d1[ord(s1[c]) - ord('a')] += 1

        for r in range(len(s1)):
            d2[ord(s2[r]) - ord('a')] += 1
        
        if d1 == d2:
            return True

        for r in range(len(s1), len(s2)):
            d2[ord(s2[l]) - ord('a')] -= 1
            d2[ord(s2[r]) - ord('a')] += 1
            l += 1
            if d2 == d1:
                return True
        
        return False