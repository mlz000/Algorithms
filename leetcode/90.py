class Solution(object):
   def subsetsWithDup(self, a):
        ans = [[]]
        a.sort()
        for i in range(len(a)):
            if i == 0 or a[i] != a[i - 1]:
                l = len(ans)
            for j in range(len(ans) - l, len(ans)):
                ans.append(ans[j] + [a[i]])
            print(ans)
        return ans