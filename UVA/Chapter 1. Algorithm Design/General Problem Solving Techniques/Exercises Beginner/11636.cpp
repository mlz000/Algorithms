#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int main()
{
     int n;
     int T=0; 
      while(scanf("%d",&n)&&(n>0))
      {
        T++;
        int i;
        for(i=0;;++i)
         if((1ll<<i)>=n) break; 
        printf("Case %d: %d\n",T,i);
      }
     // system("pause");
      return 0;
}
