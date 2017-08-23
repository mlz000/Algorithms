class Solution(object):
    def uncommon(self, s1, s2):
        l1, l2 = len(s1), len(s2)
        i = j = 0
        while i < l1 and j < l2:
            if s1[i] == s2[j]:
                j += 1
            i += 1
        return j != l2
    def findLUSlength(self, strs):
        cnt = collections.Counter(strs)
        a = sorted(set(strs), key=len, reverse=True)
        for i, c in enumerate(a):
            if cnt[c] > 1: continue
            if all(self.uncommon(p, c) for p in a[ : i]):   return len(c)
        return -1