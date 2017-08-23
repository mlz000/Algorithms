#include<stdio.h>
#include<stdlib.h>
int n,m,i,j;
int check()
{
    int f=0;
    for(i=2;i<n;++i)
    f=(f+m)%i;
    if(f==0) return 1;
    else return 0;
}
int main()
{
    while(scanf("%d",&n)&&n)
    {
        m=1;
        while(!check()) ++m;
        printf("%d\n",m);
    }
    system("pause");
    return 0;
}
        
                    
                         
                                     
    
