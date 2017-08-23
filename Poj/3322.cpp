//#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <climits>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long LL;
#define pb push_back
#define mp make_pair
#define F first
#define S second
inline void read(LL &t) {
    int f = 1;char c;
    while (c = getchar(), c < '0' || c > '9') if (c == '-') f = -1;
    t = c - '0';
    while (c = getchar(), c >= '0' && c <= '9') t = t * 10 + c - '0';
    t *= f;
}
struct data {
    int x, y;      
    int step, state;  
    data() {}
    data(int x, int y, int step, int state)	: x(x), y(y), step(step), state(state) {}
};
const int N = 505;
const int dir[3][4][3] = {
	{{2, 0, 2}, {-1, 0, 2}, {0, -1, 1}, {0, 2, 1}},
    {{0, -2, 0}, {0, 1, 0}, {-1, 0, 1}, {1, 0, 1}}, 
    {{-2, 0, 0}, {1, 0, 0}, {0, 1, 2}, {0, -1, 2}}
};
char s[N][N];
bool vis[N][N][3];
int n, m;
bool judge(int x, int y, int state) {
    if (x >= 1 && x <= n && y >= 1 && y <= m && s[x][y] != '#') {
        if (state == 0 && s[x][y] != 'E') {
            return 1;
        }
        if (state == 1 && y > 1 && s[x][y - 1] != '#') {
            return 1;
        }
        if (state == 2 && x > 1 && s[x - 1][y] != '#') {
            return 1;
        }
    }
    return 0;
}

int bfs(const data& st, const data& ed) {
    queue<data> Q;
    Q.push(st);
    vis[st.x][st.y][st.state] = 1;
    while (Q.size()) {
        data u = Q.front();
        Q.pop();
        if (u.x == ed.x && u.y == ed.y && u.state == ed.state)
            return u.step;
        for (int i = 0; i < 4; i++) {
            int x = u.x + dir[u.state][i][0];
            int y = u.y + dir[u.state][i][1];
            int state = dir[u.state][i][2];
            if (!vis[x][y][state] && judge(x, y, state)) {
                vis[x][y][state] = 1;
                Q.push(data(x, y, u.step + 1, state));
            }
        }
    }
    return -1;
}
int main() {
    while (scanf("%d%d", &n, &m) && n && m) {
        data st, ed;
        bool f = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%s", s[i] + 1);
            for (int j = 1; j <= m; j++) {
                if (s[i][j] == 'O') {
                    ed.x = i, ed.y = j, ed.state = 0;
                } 
				else if (s[i][j] == 'X') {
                    if (!f) {
                        f = 1;
                        st.x = i, st.y = j, st.state = 0;
                    } 
					else {
                        if (st.x == i) {
                            st.y = max(st.y, j);
                            st.state = 1;
                        } 
						else if (st.y == j) {
                            st.x = max(st.x, i);
                            st.state = 2;
                        }
                    }
                }
                vis[i][j][0] = vis[i][j][1] = vis[i][j][2] = 0;
            }
        }
        st.step = 0;
        int ans = bfs(st, ed);
        if (ans == -1)	puts("Impossible");
        else	printf("%d\n", ans);
    }
    return 0;
}
