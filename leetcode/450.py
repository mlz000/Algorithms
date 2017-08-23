class Solution(object):
    def deleteNode(self, root, key):
        if not root: return None  
        if root.val == key:
            if root.left:
                t = root.left
                while t:
                    t = t.right
                t = root.right
                return root.left
            else:
                return root.right
        elif root.val > key:
            root.left = self.deleteNode(root.left, key)
        else:
            root.right = self.deleteNode(root.right, key)
        return root