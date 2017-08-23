class Solution(object):
    def findDisappearedNumbers(self, a):
        for i in xrange(len(a)):
            p = abs(a[i]) - 1
            a[p] = - abs(a[p])
        return [i + 1 for i in range(len(a)) if a[i] > 0]
