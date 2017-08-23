class Solution(object):
    def combine(self, n, k):
        def dfs(last, n, k, path):
            if k == 0:
                ans.append(path)
                return
            for i in xrange(last + 1, n + 1):
                dfs(i, n, k - 1, path + [i])
        ans = []
        kk = min(k, n - k)
        dfs(0, n, kk, [])
        if k != kk:
            for i in xrange(len(ans)):
                t = []
                for j in xrange(1, n + 1):
                    if j not in ans[i]:
                        t.append(j)
                ans[i] = t
        return ans