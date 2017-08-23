#include<stdio.h>
#include<stdlib.h>
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MIN4(a,b,c,d) MIN(MIN(a,b),MIN(c,d))
int a[5850];
int main()
{
    int k,ten,n=1,p1=1,p2=1,p3=1,p4=1;
    a[1]=1;
   while(n<5842)
   {
        a[++n]=MIN4(2*a[p1],3*a[p2],5*a[p3],7*a[p4]);
              if(a[n]==2*a[p1]) p1++;
              if(a[n]==3*a[p2]) p2++;
              if(a[n]==5*a[p3]) p3++;
              if(a[n]==7*a[p4]) p4++;
   }
   while(scanf("%d",&k)&&k)
   {
        printf("The %d",k);
        ten=k/10%10;
        if(k%10==1&&ten!=1) printf("st");
        else if(k%10==2&&ten!=1) printf("nd");    
        else if(k%10==3&&ten!=1) printf("rd");
        else printf("th");
        printf(" humble number is %d.\n",a[k]);
   }
   return 0;
}   
