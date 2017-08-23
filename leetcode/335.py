class Solution(object):
    def isSelfCrossing(self, a):
        n = len(a)
        if n <= 3: return False
        for i in xrange(3, n):
            if a[i - 1] <= a[i - 3] and a[i] >= a[i - 2]:   return True
            if i >= 4 and a[i - 1] == a[i - 3] and a[i] + a[i - 4] >= a[i - 2]:    return True
            if i >= 5 and a[i - 1] + a[i - 5] >= a[i - 3] and a[i] + a[i - 4] >= a[i - 2] and a[i - 2] >= a[i - 4] and a[i - 1] <= a[i - 3]:  return True
        return False