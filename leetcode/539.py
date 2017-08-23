class Solution(object):
    def findMinDifference(self, t):
        a = sorted(map(int, x.split(':')) for x in t)
        print (a)
        a += [[a[0][0] + 24, a[0][1]]]
        return min((a[x + 1][0] - a[x][0]) * 60 + a[x + 1][1] - a[x][1] for x in range(len(a) - 1))