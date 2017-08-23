#include <iostream>
#include <cstdio>
int f(int m,int n)
{ 
	if(m<0)
   return 0;
  if(m==0||n==1)
   return 1;
  return f(m-n,n)+f(m,n-1);
}
int main()
{
    int i,j,n,m,t;
    scanf("%d",&t);
    while(t--)
    {
	 scanf("%d%d",&m,&n);
	 printf("%d\n",f(m,n));
	}
    system("pause");
    return 0;
}
