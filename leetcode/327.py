class Solution(object):
    def countRangeSum(self, a, lower, upper):
        n = len(a)
        sum, c, ans = [0] * (n + 1), [0] * (n + 2), 0
        
        def ask(x):
            t = 0
            while x:
                t += c[x]
                x -= x & -x
            return t
        
        def add(x):
            while x <= n + 1:
                c[x] += 1
                x += x & -x
                
        for i in xrange(n):  sum[i + 1] = sum[i] + a[i]
        b = sorted(sum)
        for x in sum:
            now = ask(bisect.bisect_right(b, x - lower)) - ask(bisect.bisect_left(b, x - upper))
            ans += now
            add(bisect.bisect_left(b, x) + 1)
        return ans