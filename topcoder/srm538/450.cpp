#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define F first
#define S second
typedef long long LL;
typedef pair<int, int> pii;
vector<int> a, b;//ang back
int dp[60][360];
const double Pi = acos(-1.0);
class TurtleSpy {
	public:
        double maxDistance(vector <string> commands) {
   			int n = commands.size();
			double X = 0.0, Y = 0.0;
			for (int i = 0; i < n; ++i) {
				char s[10];
				int x;
				sscanf(commands[i].c_str(), "%s%d", s, &x);
				if (s[0] == 'f')	X += x;
				else if (s[0] == 'b')	Y += x;
				else if (s[0] == 'l')	a.pb(x);
				else	a.pb(360 - x);
			}
			dp[0][0] = 1;
			for (int i = 0; i < a.size(); ++i) {
				for (int j = 0; j < 360; ++j)
					if (dp[i][j])	dp[i + 1][(j + a[i]) % 360] = dp[i + 1][j] = 1;
			}
			double t = 0.0;
			for (int i = 0; i < 360; ++i) {
				if (dp[a.size()][i])	t = max(t, X * X + Y * Y - 2.0 * X * Y * cos(Pi * i / 180.0));
			}
			return sqrt(t);
		}
};
