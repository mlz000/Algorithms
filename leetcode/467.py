class Solution(object):
    def findSubstringInWraproundString(self, p):
        n = len(p)
        cnt, last = [0] * 26, 1
        for i in xrange(n):
            t = ord(p[i]) - ord('a')
            if i > 0 and ((ord(p[i - 1]) + 1 == ord(p[i])) or (p[i - 1] == 'z' and p[i] == 'a')):
                last += 1
            else:
                last = 1
            cnt[t] = max(cnt[t], last)
        return sum(cnt)