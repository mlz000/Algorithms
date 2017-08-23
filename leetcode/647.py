class Solution(object):
    def countSubstrings(self, s):
        ss = '?#' + '#'.join(s) + '#$'
        mx, id, n = 0, 0, len(ss)
        p = [0] * n
        for i in xrange(1, n - 1):
            if mx > i:  p[i] = min(p[2 * id - i], mx - i)
            else:   p[i] = 1
            while ss[i + p[i]] == ss[i - p[i]]: 
                p[i] += 1
            if i + p[i] > mx:   mx, id = i + p[i], i
        return sum(x / 2 for x in p)