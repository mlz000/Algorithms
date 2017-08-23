class Solution(object):
    def minWindow(self, s, t):
        mp, cnt = collections.Counter(t), len(t)
        i = l = 0; r = -1
        for j, c in enumerate(s):
            cnt -= mp[c] > 0
            mp[c] -= 1
            if cnt == False:
                while i <= j and mp[s[i]] < 0:
                    mp[s[i]] += 1
                    i += 1
                if r == -1 or j - i <= r - l:
                    l, r = i, j
        return s[l : r + 1]