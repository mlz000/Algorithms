#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, d, x, a[N], b[N], q[N], pos[N];
int getNextX() {
    x = (37ll * x + 10007) % 1000000007;
    return x;
}
void initAB() {
    for(int i = 0; i < n; i = i + 1){
        a[i] = i + 1;
    }
    for(int i = 0; i < n; i = i + 1){
        swap(a[i], a[getNextX() % (i + 1)]);
    }
    for(int i = 0; i < n; i = i + 1){
        if (i < d)
            b[i] = 1;
        else
            b[i] = 0;
    }
    for(int i = 0; i < n; i = i + 1){
        swap(b[i], b[getNextX() % (i + 1)]);
    }
}
int main() {
	scanf("%d%d%d", &n, &d, &x);
	initAB();
	for (int i = 0; i < n; ++i)	pos[a[i]] = i;
	for (int i = 0; i < n; ++i)	
		if (b[i])	q[++q[0]] = i;
	int s = 30;
	for (int i = 0; i < n; ++i) {
		bool f = 1;
		for (int j = n; j > n - s && j; --j) {
			if (pos[j] <= i && b[i - pos[j]]) {
				f = 0;
				printf("%d\n", j);
				break;
			}
		}
		if (f) {
			int ans = 0;
			for (int j = 1; j <= q[0] && q[j] <= i; ++j ){
				ans = max(ans, a[i - q[j]]);
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}

