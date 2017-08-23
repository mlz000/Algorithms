class Solution(object):
    def containsNearbyAlmostDuplicate(self, a, k, t):
        if t < 0 or k < 0:   return False
        n, w, d = len(a), t + 1, {}
        if n <= 1:  return False
        for i in xrange(n):
            p = a[i] / w
            if p in d:
                return True
            if p - 1 in d and abs(a[i] - d[p - 1]) <= t:    return True
            if p + 1 in d and abs(a[i] - d[p + 1]) <= t:    return True
            d[p] = a[i]
            if i >= k:  del d[a[i - k] / w]
        return False