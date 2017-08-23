class Solution(object):
    def maxPathSum(self, root):
        ans = [-3e9]
        def f(root):
            if root == None:    return 0
            l, r = max(0, f(root.left)), max(0, f(root.right))
            ans[0] = max(ans[0], l + r + root.val)
            return max(l, r) + root.val
        f(root)
        return ans[0]