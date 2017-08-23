class Solution(object):
    def nearestPalindromic(self, n):
        l = len(n)
        S = set((str(10 ** l + 1), str(10 ** (l - 1) - 1)))
        ss = int(n[:(l + 1) / 2])
        for i in map(str, (ss - 1, ss, ss + 1)):
            S.add(i + [i, i[:-1]][l & 1][::-1])
        S.discard(n)
        return min(S, key = lambda x: (abs(int(x) - int(n)), int(x)))