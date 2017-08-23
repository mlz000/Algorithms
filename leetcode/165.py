class Solution(object):
    def compareVersion(self, version1, version2):
        v1, v2 = (map(int, t.split('.')) for t in [version1, version2])
        d = max(len(v1), len(v2))
        return cmp(v1 + [0] * (d - len(v1)), v2 + [0] * (d - len(v2)))