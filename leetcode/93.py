class Solution(object):
    def restoreIpAddresses(self, s):
        def dfs(s, k, tmp):
            if len(s) > k * 3:  return
            if k == 0:  ans.append(tmp)
            for i in xrange(min(3, len(s) - k + 1)):
                if i == 2 and int(s[:3]) > 255 or (i > 0 and s[0] == '0'):  continue
                dfs(s[i + 1:], k - 1, tmp + [s[: i + 1]])
                
        ans = []
        dfs(s, 4, [])
        return ['.'.join(x) for x in ans]    