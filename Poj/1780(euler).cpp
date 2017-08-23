#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
int a[N / 10];
int ans[N];
int tot;
stack<int> s;
void gao(int v, int m) {
    int w;
    while (a[v] < 10) {
        w = v * 10 + a[v]; 
		++a[v];
        s.push(w);
        v = w % m;
    }
}
int main(){
    int n;
    while (scanf("%d", &n) && n){
        int m = 1;
		for (int i = 1; i < n; ++i)	m *= 10;
        for (int i = 0; i <= m; ++i)	a[i] = 0;
        tot = 0;
        gao(0, m);
        while (!s.empty()) {
            int v = s.top();
            s.pop();
            ans[tot++] = v % 10;
            v /= 10;
            gao(v, m);
        }
        for (int i = 1; i < n; ++i) printf("0");
        for (int i = tot - 1; i >= 0; --i)
            printf("%d",ans[i]);
        puts("");
    }
    return 0;
}
