#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int a[101];
int main()
{
     int i,j,k,n;
    while (scanf("%d",&n),n!=0)
   {
                for(i=0;i<n;i++)
                scanf("%d",&a[i]);
                if(n%2) 
                {
                        printf("1\n");       
                        continue;
                }               
                    sort(a,a+n); 
                       for(i=0;i<n;i=i+2)
                        if(a[i]!=a[i+1]) 
                       {
                                    printf("1\n"); 
                                    goto back;
                       }
                    printf("0\n");
                    back:;    
    }    
    return 0;
}
