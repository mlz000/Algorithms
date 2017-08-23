class Solution(object):
    def calcEquation(self, equations, values, queries):
        G = collections.defaultdict(dict)
        for (num, den), val in zip(equations, values):
            G[num][num] = G[den][den] = 1.0
            G[num][den] = val
            G[den][num] = 1 / val
        for k in G:
            for i in G[k]:
                for j in G[k]:
                    G[i][j] = G[i][k] * G[k][j]
        return [G[num].get(den, -1.0) for num, den in queries]
