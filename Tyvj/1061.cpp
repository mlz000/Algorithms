#include<cstdio>
#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
const int L=205;
int f[2][L][L]; 
int c[L][L];
int l,n;
void clean(int task)
{
    int p,q,r;
	for(p=1;p<=l;++p)
	 for(q=1;q<=l;++q)
	  f[task][p][q]=9999999;
}
int main()
{
      int i,j,k;
      scanf("%d%d",&l,&n);
      for(i=1;i<=l;++i)
       for(j=1;j<=l;++j)
        scanf("%d",&c[i][j]);
       int a,b;
       scanf("%d",&a);
	   clean(1);
       f[1][1][2]=f[1][2][1]=c[3][a];
       f[1][2][3]=f[1][3][2]=c[1][a];
       f[1][1][3]=f[1][3][1]=c[2][a];      
       for(i=2;i<=n;++i)
        {
			scanf("%d",&b);
			clean(i%2);
			for(j=1;j<=l;++j)
			 for(k=1;k<=l;++k)
			 {
			   if(j==k) continue;		
			   f[i%2][j][k]=min(f[i%2][j][k],f[(i-1)%2][j][k]+c[a][b]);
			   f[i%2][j][a]=min(f[i%2][j][a],f[(i-1)%2][j][k]+c[k][b]);
			   f[i%2][k][a]=min(f[i%2][k][a],f[(i-1)%2][j][k]+c[j][b]);
			 }
			 a=b;
		}
		int ans=INT_MAX;
		for(i=1;i<=l;++i)
		 for(j=1;j<=l;++j)
		  ans=min(ans,f[n%2][i][j]);
		  printf("%d",ans);
		  //system("pause");
		  return 0;
} 
