#include <cstdio>
#include <iostream>
using namespace std;
int tt, t, n, N = 500000;
unsigned f[500020];
int main() {
    for (int i = 1; i <= N; i++) {
        for (int j = i; j <= N; j += i) {
            f[j] += (long long)(j / i) * (j / i + 1) / 2 * j;
        }
    }
    for (int i = 1; i <= N; i++) {
        f[i] += f[i - 1];
    }
    for(scanf("%d", &t); t--;) {
        scanf("%d", &n);
        printf("Case #%d: %u\n", ++tt, f[n]);
    }
    return 0;
}
