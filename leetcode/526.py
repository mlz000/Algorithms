class Solution(object):
    def countArrangement(self, N):
        def count(i, X):
            if i > N:
                return 1
            return sum(count(i + 1, X - {x})
                   for x in X
                   if x % i == 0 or i % x == 0)
        return count(1, set(range(1, N + 1)))