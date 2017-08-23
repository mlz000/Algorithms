#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
const int N=5005;
int a[N],b[N];
int n;
bool check(int k)  
{  
    int suma=0,sumb=0,count=0,coua=0,coub=0;  
    for(int i=1;i<=n;i++)  
    {  
         suma+=a[i];  
         sumb+=b[i];  
        if(a[i]>k+1||b[i]>k+1)   return false;  
        while(suma>k+1)  
        {  
            if(count==0||coua==0)   return false;  
            count--;  
            coua--;  
            suma--;  
        }  
        while(sumb>k+1)  
        {  
             if(count==0||coub==0)  
             return false;  
             count--;  
             coub--;  
             sumb--;  
        }  
        if(coua<suma)   coua++;  
        if(coub<sumb)   coub++;  
        if(count<suma+sumb)  count++;  
    }  
    return true;  
}  
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int suma=0;
        int sumb=0;
        for(int i=1;i<=n;++i) 
        {
            scanf("%d%d",&a[i],&b[i]);
            suma+=a[i];
            sumb+=b[i];
        }
        int l=0;int r=max(suma,sumb)*2;int ans=0;
        while(l<=r)
        {
            if(l==r) break;
            int mid=(l+r)>>1;
            if(check(mid)) r=mid;
            else l=mid+1;
        }
        printf("%d\n",r);
    }
   // system("pause");
    return 0;
}
