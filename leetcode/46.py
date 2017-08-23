class Solution(object):
    def permute(self, a):
        def dfs(n, a, path):
            if len(path) == n:
                ans.append(path)
                return
            for i in xrange(n):
                if not vis[i]:
                    vis[i] = True
                    dfs(n, a, path + [a[i]])
                    vis[i] = False
        n = len(a)
        ans = []
        vis = [False] * n
        dfs(n, a, [])
        return ans