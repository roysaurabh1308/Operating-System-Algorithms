

#include<stdio.h>
#include<math.h>

void main()
{
	int i,n;
	printf("Enter no. of visiting tracks:");
	scanf("%d",&n);
	int Rq[n],j,curr;
	printf("Enter the request queue:\n");
	for(i=0;i<n;i++)
	scanf("%d",&Rq[i]);
	printf("Enter current position:");
	scanf("%d",&curr);
	int track_mom[n],vis[n];
	for(i=0;i<n;i++)
	vis[i]=0;
	printf("\nS<->D\t\tTrack Movements\n");
	for(i=0;i<n;i++)
	{
		int ind,min=1000;
		for(j=0;j<n;j++)
		{
			if(!vis[j])
			{
				if(min>abs(Rq[j]-curr))
				{
					min=abs(Rq[j]-curr);
					ind=j;
				}
				else if(min==abs(Rq[j]-curr))
				{
					if(Rq[j]>Rq[ind])
					ind=j;
				}
			}
		}
		track_mom[ind]=min;
		printf("%d<->%d   \t%d\n",curr,Rq[ind],track_mom[ind]);
		curr=Rq[ind];
		vis[ind]=1;
	}
	int sum=0;
	for(i=0;i<n;i++)
	sum+=track_mom[i];
	printf("\n");
	
	printf("Toatal track moment:%d",sum);
}
