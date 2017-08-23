class Solution(object):
    def isValidSudoku(self, board):
        r, c, x = [0] * 9, [0] * 9, [0] * 9
        n = m = 9
        for i in xrange(9):
            for j in xrange(9):
                if board[i][j] != '.':
                    t, p = int(board[i][j]) - 1, i / 3 * 3 + j / 3
                    print(i, j, t, p)
                    if (r[i] >> t) & 1 > 0:
                        return False
                    r[i] |= 1 << t
                    if (c[j] >> t) & 1 > 0:
                        return False
                    c[j] |= 1 << t
                    if (x[p] >> t) & 1 > 0:
                        return False
                    x[p] |= 1 << t
        return True