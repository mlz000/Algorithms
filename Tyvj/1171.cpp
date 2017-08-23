#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int ans;
void  dfs(int lim,int left)
{
      int i;
      if(lim==1) {ans++;return;}
      if(left==0) ans++;
	  for(i=1;i<=min(left,lim);++i)
	  {
		 dfs(i,left-i); 
      }
}
int main()
{
      int n;
      scanf("%d",&n);
      dfs(n-1,n); 
    printf("%d",ans);
    //system("pause");
    return 0;
}
