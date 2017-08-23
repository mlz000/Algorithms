class Solution {
public:
    int a[3];
	int strongPasswordChecker(string s) {
        int n = s.size();
		int cnt = 0, low = 1, up = 1, dig = 1;
		memset(a, 0, sizeof(a));
		for (int i = 0, j = 0; i < n; j = i) {
			if (s[i] >= 'a' && s[i] <= 'z')	low = 0;
			if (s[i] >= 'A' && s[i] <= 'Z')	up = 0;
			if (s[i] >= '0' && s[i] <= '9')	dig = 0;
			int now = 0;
			while (i < n && s[j] == s[i]) ++i, ++now;
			cnt += now / 3;
			if (now >= 3)	++a[now % 3];
		}
		int need = low + up + dig;
		if (n < 6)	return max(6 - n, max(cnt, need));
    	else if (n <= 20)	return max(cnt, need);
		else {
			int del = n - 20;
			if (del <= a[0])	cnt -= del;
			else if ((del - a[0]) <= 2 * a[1])	cnt -= a[0] + (del - a[0]) / 2;
			else cnt -= a[0] + a[1] + (del - a[0] - 2 * a[1]) / 3;
			return del + max(cnt, need);
		}
	}
};
