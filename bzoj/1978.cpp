//http://www.zybbs.org/JudgeOnline/problem.php?id=1978
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=1005,MAXD=1000005;
int n,m,l,ans;
int a[MAXN];
int f[MAXD];
int main()
{
     int i,j,tmp;
     scanf("%d%d",&n,&l);
     for(i=1;i<=n;++i)
     {
	     scanf("%d",&m);
	     a[0]=0;//¸öÊý
		 for(j=1;j*j<=m;++j)
		 {
		    if(m%j==0)
		     {
			     if(j>=l) a[++a[0]]=j;
			     if(m/j>=l) a[++a[0]]=m/j;
			 }
		 }
		   for(j=tmp=1;j<=a[0];++j)
		   {
		     tmp=max(tmp,f[a[j]]+1);
		   }
		   for(j=1;j<=a[0];++j)
		   f[a[j]]=max(tmp,f[a[j]]);
		   ans=max(ans,tmp);       
	}
	printf("%d\n",ans);
	//system("pause");
	return 0;   
} 
