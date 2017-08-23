class Solution(object):
    def isValidBST(self, root, mn = -2 ** 32, mx = 2 ** 32):
        if not root:
            return True
        if root.val >= mx or root.val <= mn:
            return False
        return self.isValidBST(root.left, mn, root.val) and self.isValidBST(root.right, root.val, mx)