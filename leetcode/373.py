class Solution(object):
    def kSmallestPairs(self, a, b, k):
        ans = []
        heap = [(2 ** 30, None, None)]
        l1, l2 = len(a), len(b)
        if l1 == 0 or l2 == 0 or k <= 0:    return ans
        for j in xrange(l2):    heapq.heappush(heap, (a[0] + b[j], 0, j))
        for i in xrange(min(l1 * l2, k)):
            now, x, y = heapq.heappop(heap)
            print(now, x, y)
            ans.append((a[x], b[y]))
            if x == l1 - 1:  continue
            heapq.heappush(heap, (a[x + 1] + b[y], x + 1, y))
        return ans