class Solution(object):
    def partition(self, s):
        def ok(s):
            return s == s[::-1]
        def dfs(s, now):
            if not s:   
                ans.append(now)
                return 
            for i in xrange(len(s)):
                if ok(s[ : i + 1]):
                    dfs(s[i + 1 : ], now + [s[ : i + 1]])
        ans = []
        dfs(s, [])
        return ans