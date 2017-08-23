class Solution(object):
    def shoppingOffers(self, price, special, needs):
        dp = {}
        def solve(tup):
            if tup in dp: return dp[tup]
            dp[tup] = sum(t * p for t, p in zip(tup, price))
            for sp in special:
                ntup = tuple(t - s for t, s in zip(tup, sp))
                if min(ntup) < 0: continue
                dp[tup] = min(dp[tup], solve(ntup) + sp[-1])
            return dp[tup]
        return solve(tuple(needs))