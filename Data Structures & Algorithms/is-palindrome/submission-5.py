class Solution:
    def isPalindrome(self, s: str) -> bool:
        if len(s) <= 1:
            return True
        def isAlphanumeric(s: str) -> bool:
                return (ord(s) >= ord('a') and ord(s) <= ord('z')) or ((ord(s) >= ord('0') and ord(s) <= ord('9')))
        start = 0
        end = len(s) - 1
        s = s.lower()
        while (start != end or abs(start - end) != 1) and start < len(s) and end >= 0:
            while start < len(s) and end >= 0 and not isAlphanumeric(s[start]):
                start += 1;
            while start < len(s) and end >= 0 and not isAlphanumeric(s[end]):
                end -= 1;
            if start < len(s) and end >= 0 and s[start] != s[end]:
                return False
            start += 1
            end -= 1
        return True
    