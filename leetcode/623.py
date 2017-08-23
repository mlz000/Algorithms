class Solution(object):
    def addOneRow(self, root, v, d):
        def dfs(root, v, d, dep):
            if not root:
                return 
            if dep == d - 1:
                l, r = root.left, root.right
                t1, t2 = TreeNode(v), TreeNode(v)
                t1.left, t2.right = l, r
                root.left, root.right = t1, t2
                return 
            else:
                dfs(root.left, v, d, dep + 1)
                dfs(root.right, v, d, dep + 1)
        dummy = TreeNode(-1)
        dummy.left = root
        dfs(dummy, v, d, 0)
        return dummy.left
        