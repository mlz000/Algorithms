#define pb push_back
#define mp make_pair
class Solution {
public:
    int maxPoints(vector<Point>& p) {
 		int n = p.size();
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			int sm = 1, ver = 1;
			map<pair<int, pair<int, int> >, int > a;
			for (int j = i + 1; j < n; ++j) {
				if (p[i].x == p[j].x) {
					if (p[i].y == p[j].y)	++sm;
					else ++ver;
					continue;
				}
				int y = p[i].y - p[j].y, x = p[i].x - p[j].x;
				int sgn = (long long)x * y > 0 ? 1 : -1;
				int c = __gcd(abs(x), abs(y));
				++a[mp(sgn, mp(abs(x) / c, sgn * abs(y) / c))];
			}
			ans = max(ans, max(sm, ver));
			for (auto v : a)
				ans = max(ans, sm + v.second);
		}
		return ans;
    }
};
