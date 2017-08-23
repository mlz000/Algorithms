#include<cstdio>
#include<climits> 
#include<iostream>
#include<algorithm>
using namespace std;
const int N=2005; 
struct data
{
  double x;
  double y; 
}a[N]; 
int main()
{
    int n,i,j,ansa,ansb; 
    scanf("%d",&n);
	for(i=1;i<=n;++i)
	 cin>>a[i].x>>a[i].y; 
	double ans,MIN=2000000000; 
	for(i=1;i<n;++i)
	 for(j=i+1;j<=n;++j)
	 {
	   ans=(a[i].x-a[j].x)*(a[i].x-a[j].x)+(a[i].y-a[j].y)*(a[i].y-a[j].y); 
	   if(ans<0) ans=-ans; 
	   if(ans<=MIN) {MIN=ans;ansa=i,ansb=j;} 
	 }   
	 printf("%d %d",min(ansa,ansb),max(ansa,ansb));
	 //system("pause");
	 return 0; 
} 
