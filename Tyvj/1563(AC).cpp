#include<stdio.h>
#include<stdlib.h>
inline int min(int a,int b){return a<b?a:b;}
inline int max(int a,int b){return a>b?a:b;}
const int maxn=1510;
bool map[maxn][maxn];
int f[maxn][maxn],f2[maxn][maxn],n,m,ans,i,j,t;
int main(){
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
     for(j=1;j<=m;j++)
     {
        scanf("%d",&t);
        if(!(i&1||j&1))t^=1;
        if((i&1)&&(j&1))t^=1;
map[i][j]=(bool)t;
   }   
   for(i=n;i>=1;i--) 
   for(j=m;j>=1;j--){
                     if(map[i][j])f[i][j]=min(min(f[i+1][j],f[i+1][j+1]),f[i][j+1])+1;
else f2[i][j]=min(min(f2[i+1][j],f2[i+1][j+1]),f2[i][j+1])+1;
ans=max(ans,max(f[i][j],f2[i][j]));
 }
printf("%d\n",ans);
return 0;   
//һ���Ǻ�����������궼��������ż������ΪA�ࡣһ���Ǻ���������������ż���������ż����������������ΪB�ࡣͬһ���еĵ㲻����
//����Ҫ�����������ʵ���Էֳ����������Ҳ����A���϶���1��B���϶���0����A���϶���0��B�඼��1�� 
}
