class Solution(object):
    def zigzagLevelOrder(self, root):
        now, ans, q = -1, [], []
        if not root: return []
        q.append(root)
        while q:
            q2, t = [], []
            for x in q:
                if x:   t.append(x.val)
            ans.append(t)
            for x in q[::-1]:
                if now == 1:
                    if x.left: q2.append(x.left)
                    if x.right: q2.append(x.right)
                else:
                    if x.right: q2.append(x.right)
                    if x.left: q2.append(x.left)
            q = q2
            now *= -1
        return ans