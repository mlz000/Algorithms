class Solution(object):
    def update(self, board, m, n, i, j):
        live = 0
        for p in xrange(max(i - 1, 0), min(i + 2, m)):
            for q in xrange(max(j - 1, 0), min(j + 2, n)):
                live += board[p][q] & 1
        if live == 3 or live == board[i][j] + 3:
            board[i][j] += 2

    def gameOfLife(self, board):
        if not board or not board[0]:
            return
        m = len(board)
        n = len(board[0])
        for i in xrange(m):
            for j in xrange(n):
                self.update(board, m, n, i, j)
        for i in xrange(m):
            for j in xrange(n):
                board[i][j] >>= 1