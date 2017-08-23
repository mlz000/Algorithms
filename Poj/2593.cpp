#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
const int N= 100005;
int a[N];
int s1[N],s2[N];
int main()
{
      int i,j,n;
      while(scanf("%d",&n)&&n)
      {
		 int MIN;
		 MIN=INT_MIN;
		 int sum=0;	
        for(i=1;i<=n;++i)    
	    {
		  scanf("%d",&a[i]);
	      if(s1[i-1]>=0) s1[i]=s1[i-1]+a[i];
	      else s1[i]=a[i];
	    }
	    for(i=2;i<=n;++i)
		if(s1[i-1]>s1[i]) s1[i]=s1[i-1]; 
	    for(i=n;i>=1;--i)
	     if(s2[n-i]>=0) s2[n-i+1]=s2[n-i]+a[i];
	     else s2[n-i+1]=a[i];
	     for(i=2;i<=n;++i)
	     if(s2[i-1]>s2[i]) s2[i]=s2[i-1]; 
	     int ans;
		 ans=INT_MIN;
		for(i=1;i<n;++i)
		{
		   if(s1[i]+s2[n-i]>ans) ans=s1[i]+s2[n-i];
		}
		printf("%d\n",ans);
		memset(s1,0,sizeof(s1));
		memset(s2,0,sizeof(s2));
	  }
     // system("pause");
      return 0;
} 
