class Solution(object):
    def computeArea(self, A, B, C, D, E, F, G, H):
        t1 = (C - A) * (D - B) + (G - E) * (H - F)
        t2 = max(min(C, G) - max(A, E), 0) * max(min(D, H) - max(B, F), 0)
        return t1 - t2