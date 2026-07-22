class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        # sliding window of size len(s1)
        if len(s1) > len(s2):
            return False
        s1d = defaultdict(int)
        s2d = defaultdict(int)
        l = 0
        for c in s1:
            s1d[c] += 1

        for r in range(len(s1)):
            s2d[s2[r]] += 1
        
        if s2d == s1d:
            return True
        
        for r in range(len(s1), len(s2)):
            s2d[s2[l]] -= 1
            if s2d[s2[l]] == 0:
                s2d.pop(s2[l])
            s2d[s2[r]] += 1
            l += 1 
            print(l,r)
            print(s1d, s2d)
            if s2d == s1d:
                return True
        
        return False