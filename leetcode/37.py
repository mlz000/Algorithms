class Solution(object):
    def dfs(self, now, n):
        if now == n:    return True
        row, col = self.b[now][0], self.b[now][1]
        c = self.a[row][col]
        f = lambda x, y: (x // 3) * 3 + y // 3
        for i in self.x:   
            x = int(i)
            t = f(row, col)
            if self.r[row][x] == False and self.c[col][x] == False and self.num[t][x] == False:
                self.a[row][col] = i
                self.r[row][x], self.c[col][x], self.num[t][x] = True, True, True
                if self.dfs(now + 1, n):   return True
                self.a[row][col] = c
                self.r[row][x], self.c[col][x], self.num[t][x] = False, False, False
    def solveSudoku(self, a):
        self.r = [[False] * 10 for i in range(0, 10)]
        self.c = [[False] * 10 for i in range(0, 10)]
        self.num = [[False] * 10 for i in range(0, 10)]
        self.a = a
        self.b = []
        self.x = ["1", "2", "3", "4", "5", "6", "7", "8", "9"]
        for i in xrange(0, 9):
            for j in xrange(0, 9):
                if a[i][j] == ".":  self.b.append((i, j))
                else:
                    t = int(a[i][j])
                    self.r[i][t] = True
                    self.c[j][t] = True
                    self.num[(i // 3) * 3 + j // 3][t] = True
        self.dfs(0, len(self.b))