#include<cstdio>  //也可将2距离压缩至100，可算  本蒟蒻直接减的100
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int M=105,N=10300; 
long long a[M]; 
long long  f[N]; 
int main()
{
    int i,j,k,l,s,t,m;
    int flag; 
	scanf("%d",&l);
	scanf("%d%d%d",&s,&t,&m);
	for(i=1;i<=m;++i)
		scanf("%d",&a[i]);
	sort(&a[1],&a[m+1]);	
	if(s!=t) for(i=1;i<=m;++i)
	          {
			    while(a[i]-a[i-1]>=100)  a[i]=a[i]-100; //可直接锁定为100 
			  } 	
	flag=0; 	 
	if(s!=t) 
  { 
	for(i=t;i<=a[m];++i)
	{	
	 f[i]=9999999; 
	 for(k=flag;k<=m;++k) 
	     if(i==a[k]) {flag=k;break;} 
     for(j=s;j<=t;++j)
	 {
	   if(i==a[flag]) f[i]=min(f[i],f[i-j]+1);
	   else f[i]=min(f[i],f[i-j]); 
	 } 
	} 
	if(f[a[m]]==1) f[a[m]]++; 
	cout<<f[a[m]]-1<<endl;
  } 
   else
   {
	  int ans=0; 
	  for(i=1;i<=m;++i) 
	   a[i]=a[i-1]+(a[i]-a[i-1])%s; for(i=1;i<=m;++i) 
	  int ans=0;  
      for(i=1;i<=m;++i)
	   if(a[i]%s==0) ans++; 
	  printf("%d",ans); 
    } 
	//system("pause");
	return 0; 
} 
