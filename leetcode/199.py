class Solution(object):
    def rightSideView(self, root):
        def dfs(rt, dep):
            if not rt:
                return
            if dep not in d:
                d[dep] = 1
                ans.append(rt.val)
            dfs(rt.right, dep + 1)
            dfs(rt.left, dep + 1)
        ans, d = [], {}
        dfs(root, 0)
        return ans