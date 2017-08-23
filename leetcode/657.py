class Solution(object):
    def judgeCircle(self, s):
        x, y = 0, 0
        for c in s:
            if c == 'U':
                y += 1
            if c == 'D':
                y -= 1
            if c == 'L':
                x -= 1
            if c == 'R':
                x += 1
        return True if x == 0 and y == 0 else False