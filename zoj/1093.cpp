#include<stdio.h>
#define MAX 99999
int f[100][4],h[100];
int num;
void init(int cnt,int a,int b,int c)
{
    f[cnt][1]=a;
    f[cnt][2]=b;
    f[cnt][3]=c;
}
int dp(int cnt)
{
    int i;
    if(h[cnt]!=-1) return h[cnt];
    if(cnt>num) return 0;
    int ans=0;
    for(i=1;i<=num;++i)
    {
        if((f[cnt][1]>f[i][1]&&f[cnt][2]>f[i][2])||(f[cnt][1]>f[i][2]&&f[cnt][2]>f[i][1]))
        ans=dp(i)+f[i][3];
        if(ans>h[cnt]) h[cnt]=ans;
    }
    return h[cnt];
}
int main()
{
    int a,b,c,i,n,Case=0;
    while(scanf("%d",&n)&&n)
  {
      f[0][1]=f[0][2]=f[0][3]=MAX;
      num=0;
      for(i=0;i<n;++i)
      {
          scanf("%d%d%d",&a,&b,&c);
           init(++num,a,b,c);
           init(++num,b,c,a);
           init(++num,c,a,b);
      }
      for(i=0;i<=num;++i)
      h[i]=-1;
      printf("Case %d :maximum height = %d\n",++Case,dp(0));
  }
    return 0;
}
