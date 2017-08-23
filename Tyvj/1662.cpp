#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=12000;
int v[N],w[N],p[N],f[N];
int main()
{
      int i,j,n,m;
      int t,num;
      scanf("%d%d",&n,&m);
      for(i=1;i<=n;++i)
      scanf("%d%d%d",&v[i],&w[i],&p[i]);
      for(i=1;i<=n;++i)
      {
	        if(p[i]==0) 
	        {
			   for(j=v[i];j<=m;++j)
			   f[j]=max(f[j],f[j-v[i]]+w[i]);
			}
	    else
	    {
			    t=1;
			    num=p[i];
		    while(t<=num)
		    {
			    int tv=t*v[i];
			    int tw=t*w[i];
			    for(j=m;j>=tv;--j)
			    f[j]=max(f[j],f[j-tv]+tw);
		        num=num-t;
		        t=t<<1;
			}
	        if(num>0)
			{
			    int tv=num*v[i];
			    int tw=num*w[i];
			    for(j=m;j>=tv;--j)
			    f[j]=max(f[j],f[j-tv]+tw);
			}		
		}
	}
	  printf("%d",f[m]);
	  //system("pause");
	  return 0;
}
	  
	  
	  
	  
	  
	  
	  
	  
