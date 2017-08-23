class Solution(object):
    def generateParenthesis(self, n):
        def dfs(pos, cnt, n, s):
            if pos == n * 2:
                ans.append(s)
                return
            if (pos + 1 + cnt) / 2 + 1 <= n:
                dfs(pos + 1, cnt + 1, n, s + "(")
            if cnt > 0 and (pos + 1 - cnt) / 2 + 1 <= n:
                dfs(pos + 1, cnt - 1, n, s + ")")
        ans = []
        dfs(0, 0, n, "")
        return ans