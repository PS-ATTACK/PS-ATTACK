class Solution:
    def minSteps(self, s: str, t: str) -> int:
        s_al = [0] * 26; t_al =  [0] * 26

        for c in s:
            s_al[ord(c)-ord('a')] += 1
        for c in t:
            t_al[ord(c)-ord('a')] += 1

        count = 0 
        for i in range(26):
            diff = s_al[i] - t_al[i]
            count += abs(diff)
        return count
