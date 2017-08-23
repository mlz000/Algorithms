typedef long long LL;
class Solution {
public:
    int findKthNumber(LL n, int k) {
		int now = 1;
		--k;
		while (k > 0) {
			int cnt = 0;
			for (LL a = now, b = now + 1; a <= n; a *= 10, b *= 10)	cnt += min(n, b - 1) - a + 1;
			if (k >= cnt) {
				++now;
				k -= cnt;
			}
			else	--k, now *= 10;
		}
		return now;
    }
};