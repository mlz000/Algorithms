class Solution(object):
    def outerTrees(self, A):
        def cross(p, q, r):
            return cmp((p.x - r.x)*(q.y - r.y), (p.y - r.y)*(q.x - r.x))
        def drive(hull, r):
            hull.append(r)
            while len(hull) >= 3 and cross(*hull[-3:]) < 0:
                hull.pop(-2)
            return hull
        A.sort(key = lambda p: (p.x, p.y))
        lower = reduce(drive, A, [])
        upper = reduce(drive, A[::-1][1:], lower)
        return list(set(upper))