class Solution(object):
      def findFrequentTreeSum(self, root):
        if root == None: return []
        def getSum(node):
            if not node: 
                return 0
            s = node.val + getSum(node.left) + getSum(node.right)
            c[s] += 1
            return s

        c = collections.Counter()
        getSum(root)
        frequent = max(c.values())
        return [s for s in c.keys() if c[s] == frequent]