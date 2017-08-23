class Solution(object):
    def kthSmallest(self, a, k):
        ans = []
        heap = []
        n = len(a)
        for i in xrange(n):    heapq.heappush(heap, (a[i][0], i, 0))
        ans = 0
        for i in xrange(min(n * n, k)):
            now, x, y = heapq.heappop(heap)
            print(x, y)
            ans = a[x][y]
            if y == n - 1:  continue
            heapq.heappush(heap, (a[x][y + 1], x, y + 1))
        return ans