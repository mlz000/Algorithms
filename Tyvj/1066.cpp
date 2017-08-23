#include<cstring>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const int N=10005;
int a[N];
int main()
{
	int i,n;
	scanf("%d",&n);
    priority_queue<int,vector<int>,greater<int> >q;
    for(i=1;i<=n;++i)
     {
		 scanf("%d",&a[i]);
         q.push(a[i]);
     }
     int ans=0;
     int t1,t2;
     for(i=1;i<=n-1;++i)
     {
	    t1=q.top();
	    q.pop();
	    t2=q.top();
	    q.pop();
	    ans+=t1+t2;
	    q.push(t1+t2);
	 }
	 printf("%d\n",ans);
    return 0;
}
