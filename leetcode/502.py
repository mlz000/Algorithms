class Solution(object):
    def findMaximizedCapital(self, k, W, Profits, Capital):
        list = []
        a, n = sorted(zip(Capital, Profits)), len(Profits)
        i = 0
        for _ in xrange(k):
            while i < n:
                if a[i][0] > W: break
                heapq.heappush(list, (-a[i][1],))
                i += 1
            if not list:    break
            W -= heapq.heappop(list)[0]
        return W