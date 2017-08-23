class Solution(object):
    def findDuplicate(self, a):
        n = len(a)
        sl, fa = a[0], a[a[0]]
        while sl != fa:
            sl = a[sl]
            fa = a[a[fa]]
        sl = 0
        while sl != fa:
            sl = a[sl]
            fa = a[fa]
        return fa