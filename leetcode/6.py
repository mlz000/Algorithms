class Solution(object):
    def convert(self, s, m):
        dir = (m == 1) - 1
        ans, now = [''] * m, 0
        for c in s:
            ans[now] += c
            if now == 0 or now == m - 1:
                dir *= -1
            now += dir
        return ''.join(ans)