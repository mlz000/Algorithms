#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;
int d[205];
int main()
{
     int n,q;
     int i,j,num;
    while(scanf("%d%d",&n,&q)&&n&&q)
    {
     for(i=1;i<=n;++i)
      {
		 int x;	
		 scanf("%d",&num);
         for(j=1;j<=num;++j)
	      {
				scanf("%d",&x);
				d[x]++;
		  }
	  }   
	  int MAX=q-1;
	  int flag=0;
	   for(i=1;i<=101;++i)
	   {
	     if(d[i]>MAX) {MAX=d[i];flag=i;} 
	   }
	   printf("%d\n",flag);
	   memset(d,0,sizeof(d));
	}
//	system("pause");
	return 0;
}
