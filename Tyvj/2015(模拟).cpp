#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue> 
#include<cstring>
using namespace std;
const int N=100005;
char s[N];
int h[N];
int main()
{
     int i,j,n,x,y;
	 scanf("%d%d%d",&n,&x,&y);
     scanf("%s",s);
     int l=strlen(s);
     bool flag=false;
     int ans=0;
     int MIN=10000;
     for(i=0;i<l;++i)
     {
	   if(s[i]=='U') ans++;
	   else {ans--;MIN=min(ans,MIN);}
	 }
	 n=n-l;//ʣ�¹յ��� 
	if(x+n>=-MIN) 
   {
	 if(x+ans>=0)
	 {
	   ans=y-x-ans;//����߶� 
	   if(ans>=0 && n>=ans && (n-ans)%2==0) flag=true;
	   if(ans<0 && n+ans>=0 && (n+ans)%2==0) flag=true;
	 }
	 else 
	 {
	   n=n+x+ans;//�ȰѸ����߻�ƽ·����ʣn���յ� 
	   ans=y;
	   if(ans>=0 && n>=ans && (n-ans)%2==0) flag=true;
	   if(ans<0 && n+ans>=0 && (n+ans)%2==0) flag=true;
	   
	 }
   }
	 if(!flag) printf("T_T");
	 else printf("lala");
	 //system("pause");
	 return 0; 
} 
