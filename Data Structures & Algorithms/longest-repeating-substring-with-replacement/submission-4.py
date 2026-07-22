class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        # hashtable/map to store characters
        # in a given window we want the most frequent element
        # if window length - number of most frequent element = k, we have something there
        # we increase window length until the above isnt true, keep track of max length
        # then shrink from the other side until it is
        # repeat until we get to the end of list

        freq = [0] * 26
        l = r = 0
        longest = 0
        for r in range(len(s)):
            freq[ord(s[r]) - ord('A')] += 1
            window_length = r - l + 1
            max_freq = max(freq)
            print(l, r, max_freq, (r - l + 1) - max_freq)
            while (r - l + 1) - max_freq > k and l < r:
                freq[ord(s[l]) - ord('A')] -= 1
                l += 1
            if (r - l + 1) - max_freq <= k:
                longest = max(r - l + 1, longest)
        return longest