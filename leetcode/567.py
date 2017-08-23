class Solution(object):
    def checkInclusion(self, s1, s2):
        m, n = len(s1), len(s2)
        cnt, now = [0] * 26, [0] * 26
        for x in s1:    
            cnt[ord(x) - ord('a')] += 1
        if n < m:   return False
        l, r = 0, -1
        while r - l + 1 != m:
            now[ord(s2[r + 1]) - ord('a')] += 1
            r += 1
        while l <= r and r < n:
            ok = 1
            for i in xrange(26):
                if now[i] != cnt[i]:
                    ok = 0
                    break
            if ok == 1: return True
            now[ord(s2[l]) - ord('a')] -= 1
            if r + 1 < n: now[ord(s2[r + 1]) - ord('a')] += 1
            l += 1
            r += 1
        return False