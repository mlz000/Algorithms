#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
using namespace std;
const int p = 10000;
double xs, ys;
int x, y, ans;
int main()
{
    scanf ("%lf%lf", &xs, &ys);
    ans = 1, x = y = 0;
    ys -= 1E-10, xs += 1E-10;
    while (x == y)
          ans++, x = int (ans * xs) / 100, y = int (ans * (ys)) / 100;
    printf ("%d", ans);
    return 0;
}
