class Solution(object):
    def largestDivisibleSubset(self, a):
        S = {1: set()}
        for x in sorted(a):
            S[x] = max((S[d] for d in S if x % d == 0), key = len) | {x}
        return list(max(S.values(), key = len))