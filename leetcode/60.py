class Solution(object):
    def getPermutation(self, n, k):
        f = []
        v = [True] * (n + 1)
        f.append(1)
        for i in xrange(1, 10): f.append(f[-1] * i)
        now, ans = k - 1, ''
        for i in xrange(n - 1, -1, -1):
            x, y = divmod(now, f[i])
            for j in xrange(1, n + 1):
                if v[j]:
                    if x == 0:
                        ans += str(j)
                        v[j] = False   
                        break
                    else: x -= 1
            now = y
        return ans