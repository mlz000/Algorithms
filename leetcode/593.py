class Solution(object):
    def validSquare(self, p1, p2, p3, p4):
        def dis(p, q):
            return (p[0] - q[0]) * (p[0] - q[0]) + (p[1] - q[1]) * (p[1] - q[1])
        d = [0] * 6
        d[0], d[1], d[2], d[3], d[4], d[5] = dis(p1, p2), dis(p1, p3), dis(p1, p4), dis(p2, p3), dis(p2, p4), dis(p3, p4)
        d = sorted(d)
        if d[0] == d[3] and d[4] == d[5] and d[4] == 2 * d[0] and d[0] != 0:
            return True
        return False