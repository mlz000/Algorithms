import collections
class Solution(object):
    def findRepeatedDnaSequences(self, s):
        cnt = collections.defaultdict(int)
        l = 10
        if len(s) < 10:
            return []
        now = s[:l]
        cnt[now] = 1
        for i in xrange(l, len(s)):
            now = now[1:] + s[i]
            cnt[now] += 1
        ans = []
        for s in cnt:
            if cnt[s] > 1:
                ans.append(s)
        return ans