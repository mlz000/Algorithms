class Solution(object):
    def pathSum(self, root, sum):
        if not root: 
            return []
        if root.left == None and root.right == None:
            if sum == root.val: 
                return [[sum]]
            else: 
                return []
        a = self.pathSum(root.left, sum - root.val) + self.pathSum(root.right, sum - root.val)
        return [[root.val] + i for i in a]
        