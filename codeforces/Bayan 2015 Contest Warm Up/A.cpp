#include <bits/stdc++.h>
using namespace std;
char s[6][30] = {
                    "+------------------------+",
                    "|#.#.#.#.#.#.#.#.#.#.#.|D|)",
                    "|#.#.#.#.#.#.#.#.#.#.#.|.|",
                    "|#.......................|",
                    "|#.#.#.#.#.#.#.#.#.#.#.|.|)",
                    "+------------------------+",
                             };
int main() {
	int K;
	scanf("%d", &K);
	for (int i = 1; i <= K; ++i) {
		bool f = 1;
		for (int j = 1; j < 30 && f; j += 2)
			for (int k = 1; k < 6 && f; ++k) {
				if (s[k][j] == '#')	{
					s[k][j] = 'O';
					f = 0;
					break;
				}
			}
	}
	for (int i = 0; i < 6; ++i)	printf("%s\n", s[i]);
	return 0;
}
