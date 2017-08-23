#include <bits/stdc++.h>
using namespace std;
int a[10];
int main() {
    int sum = 0;
    for (int i = 1; i <= 5; ++i)    scanf("%d", &a[i]), sum += a[i];
    if (sum % 5 != 0 || sum < 5)    puts("-1");
    else printf("%d\n", sum / 5);
    return 0;
}

