#include<cstdio> 
#include<iostream>
#include<algorithm> 
using namespace std; 
const int N=2000005; 
int q[N]; 
int main()
{ 
      int i,j,n;
      scanf("%d",&n);
      int l=n+1;int r=n; 
      for(i=1;i<=n;++i)
      {
        int x;    
        scanf("%d",&x);
        if(x>0)  q[--l]=x;
        else if(x==-1 && l<=r) {printf("%d\n",q[l]);l++;}
        else if(x==0) 
        {
           if(r-l+1<=0) continue;
           int k=r; 
           for(j=l;j<=k && r-l<=n;++j)
            q[++r]=q[j]; 
        }  
      } 
//      system("pause");  
      return 0; 
} 

