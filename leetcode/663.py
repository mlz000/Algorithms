class Solution(object):
    def checkEqualTree(self, root):
        def dfs(rt):
            if not rt:
                return 0
            s.append(dfs(rt.left) + dfs(rt.right) + rt.val)
            return s[-1]
        s = []
        tot = dfs(root)
        return tot % 2 == 0 and tot / 2 in s[:-1]