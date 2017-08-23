#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define F first
#define S second
typedef long long LL;
inline void read(int &t) {
    int f = 1;char c;
    while (c = getchar(), c < '0' || c > '9') if (c == '-') f = -1;
    t = c - '0';
    while (c = getchar(), c >= '0' && c <= '9') t = t * 10 + c - '0';
    t *= f;
}
int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
    //    cout << n << endl;
        if (n >= 12) {
            if (n & 1) {
                printf("1 + 2\n");
                printf("%d + %d\n", 3, n + 1);
                printf("%d + %d\n", 4, n + 2);
                printf("%d / %d\n", n + 3, 5);//a[n + 4] = 4
                printf("6 + 7\n");
                printf("8 + %d\n", n + 5);
                printf("%d / 9\n", n + 6);//a[n + 7] = 3
                printf("10 / 11\n");//n+8
                printf("12 / 13\n");//n+9
                printf("%d + %d\n", n + 8, n + 9);//n+10
                printf("%d * %d\n", n + 4, n + 7);//n+11
                printf("%d * %d\n", n + 10, n + 11);
                if (n > 13) {
                    puts("14 / 15");
                    int t = n + 13;;
                    for (int i = 16; i <= n; ++i, ++t) {
                        printf("%d * %d\n", t, i);
                        ++i, ++t;
                        printf("%d / %d\n", t, i);
                    }
                    printf("%d * %d\n", t, n + 12);
                }
            }
            else {
                printf("1 + 2\n");
                printf("%d + %d\n", 3, n + 1);
                printf("%d + %d\n", 4, n + 2);
                printf("%d / %d\n", n + 3, 5);//a[n + 4] = 4
                printf("6 + 7\n");
                printf("8 + %d\n", n + 5);
                printf("%d / 9\n", n + 6);//a[n + 7] = 3
                printf("10 + 11\n");
                printf("%d / 12\n", n + 8);//a[n + 9] = 2
                printf("%d * %d\n", n + 4, n + 7);//a[n + 10] = 12
                printf("%d * %d\n", n + 9, n + 10);//a[n + 11] = 24
                if (n > 12) {
                    puts("13 / 14");//a[n + 12] = 1
                    int t = n + 12;
                    for (int i = 15; i <= n; ++i, ++t) {
                        printf("%d * %d\n", t, i);
                        ++i, ++t;
                        printf("%d / %d\n", t, i);
                    }
                    printf("%d * %d\n", t, n + 11);
                }
            }
        }
        else {
            if (n <= 3)    puts("-1");
            else {
                if (n == 4) {
                    printf("1 * 2\n");
                    printf("5 + 3\n");
                    printf("6 + 4\n");
                }
                else if (n == 5) {
                    printf("1 * 2\n");
                    printf("3 * 6\n");
                    printf("7 - 4\n");
                    printf("8 / 5\n");
                }
                else if (n == 6) {
                    puts("1 - 2");
                    puts("3 + 7");
                    puts("4 + 8");
                    puts("5 + 9");
                    puts("6 + 10");
                }
                else if (n == 7) {
                    puts("1 + 2");
                    puts("3 + 8");
                    puts("9 / 4");
                    puts("10 + 5");
                    puts("11 + 6");
                    puts("12 + 7");
                }
                else if (n == 8) {
                    puts("1 + 2");
                    puts("3 + 9");
                    puts("4 + 10");
                    puts("11 - 5");
                    puts("6 - 7");
                    puts("8 * 13");
                    puts("12 + 14");
                }
                else if (n == 9) {
                    puts("1 + 2");
                    puts("3 + 10");
                    puts("4 + 11");
                    puts("5 + 12");
                    puts("6 + 13");
                    puts("14 / 7");
                    puts("15 + 8");
                    puts("16 + 9");
                }
                else if (n == 10) {
                    puts("1 + 2");
                    puts("3 + 11");
                    puts("4 + 12");
                    puts("5 + 13");
                    puts("14 / 6");
                    puts("15 + 7");
                    puts("16 + 8");
                    puts("9 / 10");
                    puts("17 - 18");
                }
                else if (n == 11) {
                    puts("1 + 2");
                    puts("3 + 12");
                    puts("4 + 13");
                    puts("5 + 14");
                    puts("15 - 6");
                    puts("16 - 7");
                    puts("8 + 9");
                    puts("18 / 10");
                    puts("17 + 19");
                    puts("20 - 11");
                }
            }

        }
    }
    return 0;
}
