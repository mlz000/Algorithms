class Solution(object):
    def solveEquation(self, equation):
        left, right = equation.split('=')
        lx, lc = self.solve(left)
        rx, rc = self.solve(right)
        x, c = lx - rx, rc - lc
        if x: return 'x=%d' % (c / x)
        elif c: return 'No solution'
        return 'Infinite solutions'
    
    def solve(self, expr):
        x = c = 0
        num, sig = '', 1
        for ch in expr + '#':
            if '0' <= ch <= '9':
                num += ch
            elif ch == 'x':
                x += int(num or '1') * sig
                num, sig = '', 1
            else:
                c += int(num or '0') * sig
                num, sig = '', 1
                if ch == '-': sig = -1
        return x, c