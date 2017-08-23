#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<climits> 
using namespace std;
const int N=1005; 
long long d[N],w[N],f[N][N][2]; //f[i][j][0]表示i~j区间在i f[i][j][1]表示i~j区间在j 
int main()
{
    int n,v,i,j;
	scanf("%d%d",&n,&v); 
	for(i=1;i<=n;++i)
	 {
			scanf("%d%d",&d[i],&w[i]); 
			w[i]+=w[i-1];
	 } 
	 for (i=v+1;i<=n;i++)//初始化 
    {
        f[v][i][1]=f[v][i-1][1]+(d[i]-d[i-1])*(w[v-1]+w[n]-w[i-1]); 
        f[v][i][0]=f[v][i][1]+(d[i]-d[v])*(w[v-1]+w[n]-w[v]); 
    }
    for (i=v-1;i>0;i--)
    {
        f[i][v][0]=f[i+1][v][0]+(d[i+1]-d[i])*(w[i]+w[n]-w[v]);
        f[i][v][1]=f[i][v][0]+(d[v]-d[i])*(w[i-1]+w[n]-w[v-1]);
    }
	 for(i=v-1;i>=1;--i)
	  for(j=v+1;j<=n;++j)
	  { 
	   f[i][j][0]=min(f[i+1][j][0]+(d[i+1]-d[i])*(w[n]+w[i]-w[j]),f[i+1][j][1]+(d[j]-d[i])*(w[n]+w[i]-w[j]));
	   f[i][j][1]=min(f[i][j-1][1]+(d[j]-d[j-1])*(w[n]-w[j-1]+w[i-1]),f[i][j-1][0]+(d[j]-d[i])*(w[n]-w[j-1]+w[i-1])); 
	  } 
	cout<<min(f[1][n][0],f[1][n][1])<<endl;  
//	system("pause");
	return 0; 
} 
