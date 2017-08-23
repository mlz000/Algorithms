#include<iostream>
#include<algorithm>
using namespace std;
int f[205];
int main()
{
	 int t;
	 scanf("%d",&t);
     while(t--)
     {
		int i,j,n,m;
        int a,b,x,y;	
		int MAX=-1;	
	    scanf("%d",&n);
	    for(i=1;i<=n;++i)
	     {
			scanf("%d%d",&a,&b);
		    x=min(a,b);
		    y=max(a,b);
		    for(j=(x+1)/2;j<=(y+1)/2;++j)
		     f[j]++;
		 }
	     for(i=1;i<=201;++i)
	      if(f[i]>MAX) MAX=f[i];
	      printf("%d\n",MAX*10);
	      MAX=-1;
	      memset(f,0,sizeof(f));
	 }
    return 0;
} 
