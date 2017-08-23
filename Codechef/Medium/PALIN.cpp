#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
char s[N];
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%s", s);
		int l = strlen(s);
		bool f = 0;
		for (int i = 0; i < l; ++i) if (s[i] != '9')	f = 1;
		if (!f) {
			printf("1");
			for (int i = 0; i < l - 1; ++i)	printf("0");
			printf("1\n");
		}
		else {
			int ff = 0;
			int mid = l / 2 - (l & 1 ? 0 : 1);
			for (int i = 0; i < l / 2; ++i) {
				if (s[i] < s[l - i - 1])	ff = -1;
				else if (s[i] > s[l - i - 1])	ff = 1;
				s[l - i - 1] = s[i];
			}
			if (ff != 1) {
				int i = 0;
				while (s[mid - i] == '9') {
					s[l - 1 - mid + i] = s[mid - i] = '0';
					++i;
				}
				++s[mid - i];
				s[l - 1 - mid + i] = s[mid - i];
			}
			printf("%s\n", s);
		}
	}
	return 0;
}

