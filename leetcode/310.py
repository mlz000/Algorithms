class Solution(object):
    def findMinHeightTrees(self, n, edges):
        G = [set() for x in range(n)]
        for s, t in edges:
            G[s].add(t)
            G[t].add(s)
        a = [x for x in range(n) if len(G[x]) <= 1]
        while n > 2:
            n -= len(a)
            b = []
            for x in a:
                for y in G[x]:
                    G[y].remove(x)
                    if len(G[y]) == 1:
                        b.append(y)
            a = b
        return a