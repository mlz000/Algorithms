#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	int cnt = 0, f = 0;
	for (int i = 1; i <= 79; ++i) {
		for (int j = 1; j <= 80 - i; ++j) {
			int x = (j - 1) / 9 + 1, y = (j - 1) % 9 + 1;
			printf("%d %d\n", x, y);
			if(++cnt == n)	{f = 1;break;}
			printf("0 0\n");
			if(++cnt == n)	{f = 1;break;}
		}
		if (f)	break;
		int x = (80 - i) / 9 + 1, y = (80 - i) % 9 + 1;
		printf("%d %d\n", x, y);
		if(++cnt == n)	{f = 1;break;}
		x = (81 - i) / 9 + 1, y = (81 - i) % 9 + 1;
		printf("%d %d\n", x, y);
		if(++cnt == n)	{f = 1;break;}
	}
	if (!f) {
		printf("1 2\n");
		if(++cnt == n)	{return 0;}
		printf("1 1\n");
		if(++cnt == n)	{return 0;}
		for (int i = 1; i <= 78; ++i) {
			for (int j = i + 1; j <= 80; ++j) {
				int x = (j - 1) / 9 + 1, y = (j - 1) % 9 + 1;
				printf("%d %d\n", x, y);
				if(++cnt == n)	{f = 1;break;}
				printf("0 0\n");
				if(++cnt == n)	{f = 1;break;}
			}
			if (f)	break;
			printf("9 9\n");
			if(++cnt == n)	{f = 1;break;}
			int x = (i - 1) / 9 + 1, y = (i - 1) % 9 + 1;
			printf("%d %d\n", x, y);
			if(++cnt == n)	{f = 1;break;}
		}			
	}
	return 0;
}
