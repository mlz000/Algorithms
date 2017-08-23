#include<iostream>//生日蛋糕，好题 
#include<cstdio> 
#include<climits> 
#include<algorithm>
using namespace std; 
#define V(r,h) ((r)*(r)*(h))
#define SC(r,h) (2*(r)*(h))
#define SD(r) ((r)*(r)) 
const int N=10005,M=25;
int n,m,MIN,minv[M],mins[M]; 
void dfs(int num,int left,int s,int rnow,int hnow)//第num层剩下left体积，总面积s，此时该填第num层 
{
   int i,j; 
   if(num==0)
   {
     if(left==0 && s<MIN) MIN=s;
     return ; 
   } 
   if(left<minv[num] || s+mins[num]>=MIN || 2*left/rnow+s>=MIN) return ;  
   for(i=rnow-1;i>=num;--i)
   {
     if(num==m) s=SD(i); 
     int h=min(hnow-1,(left-minv[num-1])/SD(i)); 
     for(j=h;j>=num;--j)
      dfs(num-1,left-V(i,j),s+SC(i,j),i,j); 
   } 
} 
int main()
{
     scanf("%d%d",&n,&m);
     int i; 
     for(i=1;i<=20;++i)
     {
       minv[i]=minv[i-1]+V(i,i);
       mins[i]=mins[i-1]+SC(i,i); 
     } 
     MIN=INT_MAX; 
     dfs(m,n,0,n+1,n+1); 
     if(MIN==INT_MAX) printf("0"); 
     else cout<<MIN; 
     //system("pause"); 
     return 0;
}

