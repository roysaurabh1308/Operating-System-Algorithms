#include<stdio.h>
#include<math.h>

void main()
{
	int i,j,n;
	printf("Enter no. of visiting tracks:");
	scanf("%d",&n);
	int Rq[n],curr;
	printf("Enter the request queue:\n");
	for(i=0;i<n;i++)
	scanf("%d",&Rq[i]);
	printf("Enter current position:");
	scanf("%d",&curr);
	int track_mom[n];
	int cpy[n][n];
	printf("\nS<->D\t\tTrack Movements\n");
	for(i=0;i<n;i++)
	{
		track_mom[i]=abs(Rq[i]-curr);
		printf("%d<->%d   \t%d\n",curr,Rq[i],track_mom[i]);
		curr=Rq[i];
	}
	int sum=0;
	for(i=0;i<n;i++)
	sum+=track_mom[i];
	printf("\n");
	
	printf("Toatal track moment:%d",sum);
}
