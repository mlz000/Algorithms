class Solution(object):
    def longestPalindrome(self, s):
        ss = '?#' + '#'.join(s)
        mx, id, n = 0, 0, len(ss)
        ss += '#$$'
        p = [0] * (n + 5)
        for i in xrange(1, n):
            if mx > i:  p[i] = min(p[2 * id - i], mx - i)
            else:   p[i] = 1
            while ss[i + p[i]] == ss[i - p[i]]: 
                p[i] += 1
            if i + p[i] > mx:   mx, id = i + p[i], i
        mx = 0
        for i in xrange(1, n):
            if p[i] > mx:   mx, id = p[i], i
        return ''.join(ss[id - p[id] + 1 : id + p[id]].split('#'))