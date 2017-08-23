#include<stdio.h>
#include<stdlib.h> 
int a[1001];
int main()
{
   int x,y,i,j,n,m,max=0;
   char s[8];
   scanf("%d%d",&n,&m);
   while(m--)
   {
      scanf("%s",s);
      if(s[0]=='Y')
      {
           for(i=1;i<=n;i++)
           if(max<a[i]) max=a[i];     
           printf("%d\n",max);
      }
      if(s[0]=='L')
      {
           scanf("%d%d",&x,&y);
           a[x]=y;           
      }
      if(s[0]=='U') 
      {
         scanf("%d",&x);
           a[x]=0;
      }
   }
   system("pause");
   return 0;   
}
