class Solution(object):
    def numTrees(self, n):
        Cat = 1
        for i in xrange(1, n + 1):
            Cat = Cat * (4 * i - 2) / (i + 1)
        return Cat