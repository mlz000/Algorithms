#include <bits/stdc++.h>
using namespace std;
int a[] = {-1, 1, 1, -1, 1, -1, 0, 0, 1, -1, -1, 1, 0, 0, -1, 1, -1, 1, 1, -1, 0, 0, 0, 0};
int main(){
	int T;
	scanf("%d", &T);
	for(int tt = 1; tt <= T; ++tt){
		int ans = 0;
		char ch[3];
		for(int i = 0; i < 24; ++i){
			scanf("%s", ch);
			if(ch[0] == 'w' || ch[0] == 'y')	ans += a[i];
		}
		printf("Case #%d: %s\n", tt, ans % 3 ? "NO" : "YES");
	}
	return 0;
}
