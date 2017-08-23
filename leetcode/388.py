class Solution(object):
    def lengthLongestPath(self, input):
        m, l = 0, {-1: -1}
        for s in input.split('\n'):
            d = s.count('\t')
            l[d] = 1 + l[d - 1] + len(s) - d
            if '.' in s: m = max(m, l[d])
        return m