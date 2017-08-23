class Solution(object):
    def combinationSum2(self, a, target):
        def dfs(p, sum, target, a, path):
            if sum == target:   
                ans.append(path)
                return
            for i in xrange(p, len(a)):
                if i > p and a[i] == a[i - 1]:  continue
                if sum + a[i] > target: break
                dfs(i + 1, sum + a[i], target, a, path + [a[i]])
        a = sorted(a)
        print(a)
        ans = []
        dfs(0, 0, target, a, [])
        return ans