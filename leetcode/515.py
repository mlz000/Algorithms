class Solution(object):
    def largestValues(self, root):
        def dfs(root, dep):
            if not root:
                return
            if len(d) < dep + 1:
                d.append(root.val)
            else:
                d[dep] = max(d[dep], root.val)
            dfs(root.left, dep + 1)
            dfs(root.right, dep + 1)
        d = []
        dfs(root, 0)
        return d