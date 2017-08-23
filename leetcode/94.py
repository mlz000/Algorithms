class Solution(object):
    def inorderTraversal(self, root):
        s, ans = [], []
        while True:
            while root:
                s.append(root)
                root = root.left
            if not s:
                return ans
            t = s.pop()
            ans.append(t.val)
            root = t.right