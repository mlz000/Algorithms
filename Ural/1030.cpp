#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
using namespace std;
#define pi acos(-1.0)
struct node
{
    double a, b, c;
};
 
int main()
{
    double la1, lo1, la2, lo2, ans, A;
    node s, t;
    char str[100], c;
    gets(str);
    gets(str);
    gets(str);
    scanf("%lf^%lf'%lf%c %s", &s.a, &s.b, &s.c, &c, str);
    getchar();
    la1 = s.a + s.b/60 + s.c/3600;
    if(str[0] == 'S') la1 = -la1;
    scanf("%s %lf^%lf'%lf%c %s", str, &t.a, &t.b, &t.c, &c, str);
    lo1 = t.a + t.b/60 + t.c/3600;
    if(str[0] == 'W') lo1 = -lo1;
    getchar();
    gets(str);
    scanf("%lf^%lf'%lf%c %s", &s.a, &s.b, &s.c, &c, str);
    getchar();
    la2 = s.a + s.b/60 + s.c/3600;
    if(str[0] == 'S') la2 = -la2;
    scanf("%s %lf^%lf'%lf%c %s", str, &t.a, &t.b, &t.c, &c, str);
    getchar();
    lo2 = t.a + t.b/60 + t.c/3600;
    if(str[0] == 'W') lo2 = -lo2;
    gets(str);
    la1 = la1*pi/180.0; lo1 = lo1*pi/180.0;
    la2 = la2*pi/180.0; lo2 = lo2*pi/180.0;
    s.a = cos(la1)*cos(lo1); s.b = cos(la1)*sin(lo1); s.c = sin(la1);
    t.a = cos(la2)*cos(lo2); t.b = cos(la2)*sin(lo2); t.c = sin(la2);
    A = acos(s.a*t.a+s.b*t.b+s.c*t.c);
    ans = A*6875.0/2.0;
    printf("The distance to the iceberg: %.2lf miles.\n", ans);
    double res = 0.01*floor(ans*100.0);
    if(ans - res >= 0.005)
    {
        if(res + 0.01 < 100.0) printf("DANGER!\n");
    }
    else if(ans < 100.0) printf("DANGER!\n");
    return 0;
}

