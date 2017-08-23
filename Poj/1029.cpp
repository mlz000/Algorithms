#include<iostream>
#include<cstdio>
#include<climits>
#include<algorithm>
using namespace std;
bool r[2005];
int a[2005],w[2005];
int main()
{
      int i,j,n,k;
      int num=0,cnt=0,pos;
      char s[5];
      scanf("%d%d",&n,&k);
      for(i=1;i<=k;++i)
      {
	     scanf("%d",&num);
	     for(j=1;j<=num*2;++j)
	     scanf("%d",&a[j]);
	     scanf("%s",s);
	     if(s[0]=='=')
	     {
		   for(j=1;j<=num*2;++j)
		   r[a[j]]=true;
		 }
		 if(s[0]=='<') 
		 {
           for(j=1;j<=num;++j)
           if(!r[a[j]]) w[a[j]]--;
           for(j=num+1;j<=num*2;++j)
           if(!r[a[j]]) w[a[j]]++;  
           cnt++;
		 }
		 if(s[0]=='>')
		 {
            for(j=1;j<=num;++j)
           if(!r[a[j]]) w[a[j]]++;
           for(j=num+1;j<=num*2;++j)
           if(!r[a[j]]) w[a[j]]--;  
           cnt++;
		 }
	  }
	  num=0;
      for(i=1;i<=n;++i)
      {
	     if(!r[i])
		 {
				if( w[i]==cnt || w[i]==-cnt) 
	            {pos=i;num++;}
		 }
	  }
      if(num!=1) printf("0\n");
      else printf("%d\n",pos);
     //system("pause");
      return 0;
}
