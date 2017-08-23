class Solution(object):
    def sumNumbers(self, root):
        def gao(rt, now):
            if not rt.left and not rt.right:
                ans[0] += now
                print(now)
                return
            if rt.left: gao(rt.left, now * 10 + rt.left.val)
            if rt.right: gao(rt.right, now * 10 + rt.right.val)
        ans = [0]
        if not root:    return 0
        gao(root, root.val)
        return ans[0]