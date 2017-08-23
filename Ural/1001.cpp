#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const int N=100000000;
double a[N];
int main()
{
     int i=0,j;
     while(cin>>a[++i]);
     for(j=i-1;j>=1;--j)
     printf("%.4lf\n",sqrt(a[j]));
    // system("pause");
     return 0;
}

