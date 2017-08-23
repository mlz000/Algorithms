#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
int f(int x)
{
   if(x==1) return 1;
   else return f(x/2)+1; 
} 
int main()
{
      int n; 
      while(scanf("%d",&n)!=EOF)
      {
        printf("%d\n",f(n));  
      }  
      //system("pause");
      return 0;
}
