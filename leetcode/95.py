class Solution(object):
    def generateTrees(self, n):
        if n == 0:  return []
        def generate(l, r):
            trees = []
            for root in range(l, r + 1):
                for left in generate(l, root - 1):
                    for right in generate(root + 1, r):
                        node = TreeNode(root)
                        node.left = left
                        node.right = right
                        trees += node,
            return trees or [None]
        return generate(1, n)