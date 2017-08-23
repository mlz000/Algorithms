#include<cstring>
#include<queue> 
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=1000005;
int a[N],q[N],pos[N];
int n,k; 
void getmin()
{
    int i,l=1,r=0; 
    for(i=1;i<k;++i)
    {
       while(l<=r && a[i]<=q[r]) r--;
       r++;
       q[r]=a[i]; 
       pos[r]=i; 
    }  
    for(i=k;i<=n;++i)
    {
      while(l<=r && a[i]<=q[r]) r--;
      r++;
      q[r]=a[i];
      pos[r]=i;
      while(pos[l]<i-k+1) l++;
      printf("%d ",q[l]); 
    } 
} 
void getmax()
{
    int i,l=1,r=0; 
    for(i=1;i<k;++i)
    {
       while(l<=r && a[i]>=q[r]) r--;
       r++;
       q[r]=a[i]; 
       pos[r]=i; 
    }  
    for(i=k;i<=n;++i)
    {
      while(l<=r && a[i]>=q[r]) r--;
      r++;
      q[r]=a[i];
      pos[r]=i;
      while(pos[l]<i-k+1) l++;
      printf("%d ",q[l]); 
    } 
} 
int main() 
{ 
    int i; 
    scanf("%d%d",&n,&k);
    for(i=1;i<=n;++i)
     scanf("%d",&a[i]);
    getmin();
    printf("\n");
    getmax(); 
    //system("pause"); 
    return 0;
}
