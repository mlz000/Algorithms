class Solution(object):
    def isRectangleCover(self, a):
        asd = {(1, 2):3, (3, 4):5}
        n, cnt, inf, sum = len(a), {}, 10000000, 0
        x1, y1, x2, y2 = min(x[0] for x in a), min(x[1] for x in a), max(x[2] for x in a), max(x[3] for x in a)
        for i in xrange(n):
            sum += (a[i][2] - a[i][0]) * (a[i][3] - a[i][1])
            cnt[(a[i][0], a[i][1])] = cnt.get((a[i][0], a[i][1]), 0) + 1
            cnt[(a[i][0], a[i][3])] = cnt.get((a[i][0], a[i][3]), 0) + 1
            cnt[(a[i][2], a[i][1])] = cnt.get((a[i][2], a[i][1]), 0) + 1
            cnt[(a[i][2], a[i][3])] = cnt.get((a[i][2], a[i][3]), 0) + 1
        ok = True
        for i in cnt:
            if i in [(x1, y1), (x1, y2), (x2, y1), (x2, y2)]:
                if cnt[i] != 1:
                    ok = False
                    break
            elif cnt[i] != 2 and cnt[i] != 4:
                ok = False
                break
        return ok and sum == (x2 - x1) * (y2 - y1)