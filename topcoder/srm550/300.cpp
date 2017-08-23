#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define F first
#define S second
typedef long long LL;
typedef pair<int, int> pii;
int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};
const int N = 205;
bool vis[N][N];
struct RotatingBot {
    int minArea(vector <int> moves) {
		int n = moves.size();
        int x = 100, y = 100;
		int mxx = 100, mxy = 100, mnx = 100, mny = 100;
		for (int i = 0; i < n; ++i) {
			int dir = i % 4;
			int tx = x + dx[dir] * moves[i];
			int ty = y + dy[dir] * moves[i];
			mxx = max(mxx, tx), mnx = min(mnx, tx);
			mxy = max(mxy, ty), mny = min(mny, ty);
			x = tx, y = ty;
		}
		x = 100, y = 100;
		vis[x][y] = 1;
		if (mxx > 151 || mxy > 151 || mnx < 49|| mxy < 49)	return -1;
		for (int i = 0; i <= 151; ++i) {
			vis[i][mxy + 1] = vis[i][mny - 1] = 1;
			vis[mxx + 1][i] = vis[mnx - 1][i] = 1;
		}
		for (int i = 0; i < n; ++i) {
			int dir = i % 4;
			for (int j = 0; j < moves[i]; ++j) {
				int tx = x + dx[dir];
				int ty = y + dy[dir];
				if (vis[tx][ty])	return -1;
				vis[tx][ty] = 1;
				x = tx, y = ty;
			}
			if (i != n - 1 && !vis[x + dx[dir]][y + dy[dir]])	return -1;
		}
		return (mxx - mnx + 1) * (mxy - mny + 1);
    }
};
