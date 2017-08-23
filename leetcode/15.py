class Solution(object):
    def threeSum(self, a):
        n, ans = len(a), []
        a.sort()
        for i in xrange(n - 2):
            if i > 0 and a[i] == a[i-1]:
                continue
            l, r = i + 1, n - 1
            while l < r:
                s = a[i] + a[l] + a[r]
                if s < 0:   l += 1 
                elif s > 0: r -= 1
                else:
                    ans.append((a[i], a[l], a[r]))
                    while l < r and a[l] == a[l + 1]:
                        l += 1
                    while l < r and a[r] == a[r - 1]:
                        r -= 1
                    l += 1; r -= 1
        return ans