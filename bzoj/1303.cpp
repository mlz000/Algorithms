#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=100005;
int a[N],h[N<<1];
int main()
{
      int n,b;
      scanf("%d%d",&n,&b);
      int pos=0;
      for(int i=1,t=0;i<=n;++i)
      {
            scanf("%d",&a[i]);
            if(a[i]==b) pos=i;
            else t+=a[i]>b?1:-1;
            if(pos)    ++h[t+N];
      }
      int ans=h[N];
      for(int i=1,t=0;i<pos;++i)
        ans+=h[(t+=a[i]>b?1:-1)+N] ;
      printf("%d",ans);     
	return 0;
}

