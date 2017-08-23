#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=10;
int a[N][N];
int f[N][N]={{0,0,0,0,0,0,0,0,0,0},
             {0,6,6,6,6,6,6,6,6,6}, 
             {0,6,7,7,7,7,7,7,7,6},
             {0,6,7,8,8,8,8,8,7,6},
             {0,6,7,8,9,9,9,8,7,6},
             {0,6,7,8,9,10,9,8,7,6},
             {0,6,7,8,9,9,9,8,7,6},
             {0,6,7,8,8,8,8,8,7,6},
             {0,6,7,7,7,7,7,7,7,6},
             {0,6,6,6,6,6,6,6,6,6}};
int num[N][N]={{0,0,0,0,0,0,0,0,0,0},
               {0,1,1,1,2,2,2,3,3,3},
               {0,1,1,1,2,2,2,3,3,3},
               {0,1,1,1,2,2,2,3,3,3},
               {0,4,4,4,5,5,5,6,6,6},
               {0,4,4,4,5,5,5,6,6,6},
               {0,4,4,4,5,5,5,6,6,6},
               {0,7,7,7,8,8,8,9,9,9},
               {0,7,7,7,8,8,8,9,9,9},
               {0,7,7,7,8,8,8,9,9,9}};
bool usedx[N][N],usedy[N][N],used[N][N];//used数组为小格数是否出现
int ans=-1;
int cheat;
struct data
{
   int x;
   int y;
}d[N*N];//多少个未填的数字
void dfs(int cnt,int tot)
{
	 // printf("%d ",cnt);
	  if(!cnt) {ans=max(ans,tot);return;}
	  cheat++;
	  if(cheat>10000000) return ;
	  int k;
	  int x=d[cnt].x;
	  int y=d[cnt].y;
	  for(k=1;k<=9;++k)
       {
         if(!used[num[x][y]][k] && !usedx[x][k] && !usedy[y][k])
		 {
			 used[num[x][y]][k]=true;
			 usedx[x][k]=true;
			 usedy[y][k]=true;
		     dfs(cnt-1,tot+k*f[x][y]);
		     used[num[x][y]][k]=false;usedx[x][k]=false;usedy[y][k]=false;//回溯
	     }
	   } 
}
int main()
{
     int tot=0;
     int cnt=1;
     int i,j;
     for(i=1;i<=9;++i)
      for(j=1;j<=9;++j)
       {
		   scanf("%d",&a[i][j]);
		   if(a[i][j]==0) {d[cnt].x=i;d[cnt].y=j;cnt++;}
		   if(a[i][j]) 
		   {
			   usedx[i][a[i][j]]=true;
			   usedy[j][a[i][j]]=true;
		       tot+=a[i][j]*f[i][j];
			   used[num[i][j]][a[i][j]]=true;
			}
	   }
       dfs(cnt,tot);
       printf("%d\n",ans);
       return 0;
}
