class Solution(object):
    def buildTree(self, inorder, postorder):
        if not inorder or not postorder:
            return None
        root = TreeNode(postorder.pop())
        id = inorder.index(root.val)
        root.right = self.buildTree(inorder[id + 1 : ], postorder)
        root.left = self.buildTree(inorder[ : id], postorder)
        return root