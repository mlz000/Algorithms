class Solution(object):
    def rob(self, root):
        return self.dfs_rob(root)[0]
 
    def dfs_rob(self, root):
        if not root: return 0, 0
        l, r = [0] * 2, [0] * 2
        l[0], l[1] = self.dfs_rob(root.left)
        r[0], r[1] = self.dfs_rob(root.right)
        return max(l[1] + r[1] + root.val , l[0] + r[0]), l[0] + r[0]