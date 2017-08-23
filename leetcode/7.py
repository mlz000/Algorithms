class Solution(object):
    def reverse(self, x):
        inf = 2 ** 31 - 1
        x = str(x)
        if x[0] == '-':
            t = x[1:][::-1]
            if int(t) > inf + 1:
                return 0
            return int('-' + t)
        else:
            t = x[::-1]
            if int(t) > inf:
                return 0
            return int(t)  