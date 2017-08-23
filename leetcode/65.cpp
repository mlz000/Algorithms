int space(string s, int p) {
	int n = s.size();
	while (p < n && s[p] == ' ')	++p;
	return p;
}
bool sign(string s, int p) {
	return s[p] == '-' || s[p] == '+';
}
bool num(string s, int p) {
	return s[p] >= '0' && s[p] <= '9';
}
class Solution {
	public:
    bool isNumber(string s) {
    	int n = s.size();
		for (int i = 0; i < n; ++i)
			if (!num(s, i) && !sign(s, i) && s[i] != 'e' && s[i] != 'E' && s[i] != '.' && s[i] != ' ')	return 0;
		int p, dotcnt = 0, numcnt = 0;
		p = space(s, 0);
		if (sign(s, p))	++p;
		if (p >= n)	return 0;
		for (; (s[p] == '.' || num(s, p)) && p < n; ++p) {
			if (num(s, p))	++numcnt;
			else ++dotcnt;
		}
		if (dotcnt > 1 || !numcnt)	return 0;
		numcnt = 0;
		if (s[p] == 'e' || s[p] == 'E') {
			++p;
			if (sign(s, p))	++p;
			for (; num(s, p); ++p)	++numcnt;
			if (!numcnt)	return 0;
		}
		p = space(s, p);
		return p == n;
	}
};
