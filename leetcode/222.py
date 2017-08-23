class Solution(object):
    def countNodes(self, root):
        def high(root):
            rt = root
            t = 0
            while rt:
                t += 1
                rt = rt.left
            return t
        h = {}
        ans = 0
        while root:
            hl, hr = high(root.left), high(root.right)
            if hl > hr:
                ans += 1 << hr
                root = root.left
            else:
                ans += 1 << hl
                root = root.right
        return ans