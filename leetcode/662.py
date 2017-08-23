class Solution(object):
    def widthOfBinaryTree(self, root):
        def dfs(rt, dep, num):
            if not rt:
                return
            d[dep][0] = min(d[dep][0], num)
            d[dep][1] = max(d[dep][1], num)
            dfs(rt.left, dep + 1, num << 1)
            dfs(rt.right, dep + 1, (num << 1) | 1)
        lim = (10 ** 4) + 1
        d = [[0] * 2 for i in xrange(lim)]
        inf = 2 ** 31
        for i in xrange(lim):
            d[i][0] = inf
            d[i][1] = -inf
        ans = 0
        dfs(root, 0, 1)
        for i in xrange(lim):
            if d[i][0] != inf and d[i][1] != - inf:
                ans = max(ans, d[i][1] - d[i][0] + 1)
        return ans