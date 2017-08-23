class Solution(object):
    def subsets(self, a):
        S = {()}
        for x in a:
            S |= {SS + (x,) for SS in S}
        return [x for x in S]