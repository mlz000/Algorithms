class Solution(object):
    def minMoves2(self, a):
        mid = sorted(a)[len(a) / 2]
        return sum(abs(x - mid) for x in a)