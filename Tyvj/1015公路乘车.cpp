#include<stdio.h>
#include<stdlib.h>
#define MIN(a,b) a<b?a:b
main()
{
	int i,j,n,t,min,a[11],sum[501];
	for(i=1;i<=10;i++)
	scanf("%d",&a[i]);
	scanf("%d",&n);
	sum[1]=a[1];
	for(i=2;i<=n;i++)
	{
		    min=9999;
	    		 if(i<11){
						 for(j=1;j<i;j++)
				        {
				            t=sum[j]+a[i-j]; 
				            min=MIN(min,t);
				    	  }
				    	  min=MIN(min,a[i]);
					}
			  else  {   
				      for(j=i-10;j<i;j++)	      
					 	  {
						    t=sum[j]+a[i-j];
						    min=MIN(min,t);
						 }    
			        }
					sum[i]=min;
			}
	printf("%d\n",sum[n]);
}						    
					       
