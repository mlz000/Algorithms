#include<cstring>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=10;
int a[N][N],suml[N],sumx[N],sumy[N];
bool ans[N];
int x[5]={0,1,4,7,10};
int y[5]={0,1,4,7,10};
int main()
{
    int i,j,k,cnt1,cnt2,n;
    scanf("%d",&n);
    for(i=1;i<=n;++i)
    {
	   cnt1=1;
	   cnt2=1; 
	   int sum=0; 
	   memset(a,0,sizeof(a));	
	   memset(sumx,0,sizeof(sumx));
	   memset(sumy,0,sizeof(sumy));
	   memset(suml,0,sizeof(suml));
	   memset(ans,true,sizeof(ans));
	   for(j=1;j<=9;++j)
	    for(k=1;k<=9;++k)
		 {
				scanf("%d",&a[j][k]);
	            if(a[j][k]==5) sum++;
		 } 
		 for(j=1;j<=9;++j)
	       { 
			 for(k=1;k<=9;++k)    
			 { 
			  sumx[j]+=a[j][k];
			  sumy[k]+=a[j][k];
	         }
	       }
		  for(j=1;j<=9;++j)
		   {
		   if(sumx[j]!=45) ans[i]=false; 
	       if(sumy[j]!=45) ans[i]=false;   
	       } 
		 while(cnt1!=4)
	     {
			for(j=x[cnt1];j<=x[cnt1+1]-1;++j) 
	     	for(k=y[cnt2];k<=y[cnt2+1]-1;++k)
			   suml[(cnt1-1)*3+cnt2]+=a[j][k];
			 if(suml[(cnt1-1)*3+cnt2]!=45) ans[i]=false; 
			 if(cnt2==3) {cnt2=1;cnt1++;} 
			 else cnt2++;	  
	     }
	     if(!ans[i] || sum==81) printf("Wrong\n");
	     else printf("Right\n");   
	}
	//system("pause"); 
    return 0;
}
