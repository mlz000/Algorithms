#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=3005;
int a[N],b[N];
int f[N]; //f[j]Ϊ�ڶ�����ĩβΪjʱ�Ĵ� 
int main()
{
    int i,j,n;
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	 scanf("%d",&a[i]);
	for(i=1;i<=n;++i)
	 scanf("%d",&b[i]);
	 int ans=0; 
	 for(i=1;i<=n;++i)
	 {
	  int max=0;		 
	  for(j=1;j<=n;++j)//��b[j]λ�ã�b������a����lcis 
	  {
	    if(a[i]>b[j] && f[j]>max) max=f[j]; 
		else if(a[i]==b[j] && f[j]<max+1) f[j]=max+1;
	  }
	  }
	  for(i=1;i<=n;++i)
	   if(f[i]>ans) ans=f[i]; 
	   printf("%d",ans);
	 // system("pause");
	   return 0; 
} 
