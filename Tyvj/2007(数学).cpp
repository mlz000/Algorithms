 #include<cstring>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const double T=2.2360679774997896964091736687313; 
int main()
{
    int a,b; 
    while(scanf("%d%d",&a,&b)!=EOF)
    {
      if(b%a==0||(a==2 && b==1)) printf("1\n");
      else printf("0\n"); 
    } 
    //system("pause"); 
    return 0;
}
