class Solution:
    def combinationSum3(self, k, n):
        if n > sum([i for i in range(1, 11)]):
            return []
        res = []
        self.sum_help(k, n, 1, [], res)
        return res

    def sum_help(self, k, n, curr, arr, res):
        if len(arr) == k:
            if sum(arr) == n:
                res.append(list(arr))
            return

        if len(arr) > k or curr > 9:
            return
        
        for i in range(curr, 10):
            arr.append(i)
            self.sum_help(k, n, i + 1, arr, res)
            arr.pop()