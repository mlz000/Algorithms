#include <bits/stdc++.h>
using namespace std;
const int N = 25;
char s1[N], s2[N];
int main() {
	int n, m;
	scanf("%d%d%s%s", &n, &m, s1, s2);
	if ((s1[0] == '<' && s1[n - 1] == '>' && s2[0] == 'v' && s2[m - 1] == '^')
			|| (s1[0] == '>' && s1[n - 1] == '<' && s2[0] == '^' && s2[m - 1] == 'v'))	puts("YES");
	else puts("NO");
	return 0;
}
