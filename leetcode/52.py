class Solution(object):
    def totalNQueens(self, n):
        def dfs(queens, dif, sum):
            p = len(queens)
            if p == n:
                ans.append(queens)
                return None
            for q in range(n):
                if q not in queens and p - q not in dif and p + q not in sum: 
                    dfs(queens + [q], dif + [p - q], sum + [p + q])  
        ans = []
        dfs([], [], [])
        return len(ans)