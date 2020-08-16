
#include<stdio.h>
#include<math.h>
#include"sort.c"

void main()
{
	int i,j=0,n,size;
	printf("Enter no. of tracks in disk:");
	scanf("%d",&size);
	printf("Enter no. of visiting tracks:");
	scanf("%d",&n);
	int Rq[n+2],curr,choice=0;
	printf("Enter the request queue:\n");
	for(i=1;i<n+1;i++)
	scanf("%d",&Rq[i]);
	Rq[0]=0;
	Rq[n+1]=size-1;
	ms(Rq,1,n);
	printf("Enter current position:");
	scanf("%d",&curr);
	int track_mom[n+1];
	printf("Choose Direction:\n1. Left\t2. Right\noption:");
	scanf("%d",&choice);
	printf("\nS<->D\t\tTrack Movements\n");
	while(Rq[j]<curr)
	j++;
	switch(choice)
	{
		case 1:
			for(i=j-1;i>=0;i--)
			{
				track_mom[i]=abs(Rq[i]-curr);
				printf("%d<->%d   \t%d\n",curr,Rq[i],track_mom[i]);
				curr=Rq[i];
			}
			for(i=n+1;i>=j;i--)
			{
				track_mom[i]=abs(Rq[i]-curr);
				printf("%d<->%d   \t%d\n",curr,Rq[i],track_mom[i]);
				curr=Rq[i];
			}
		break;
		default:
			for(i=j;i<n+1;i++)
			{
				track_mom[i]=abs(Rq[i]-curr);
				printf("%d<->%d   \t%d\n",curr,Rq[i],track_mom[i]);
				curr=Rq[i];
			}
			for(i=0;i<j;i++)
			{
				track_mom[i]=abs(Rq[i]-curr);
				printf("%d<->%d   \t%d\n",curr,Rq[i],track_mom[i]);
				curr=Rq[i];
			}
		break;
	}
	
	int sum=0;
	for(i=0;i<n+2;i++)
	sum+=track_mom[i];
	printf("\n");
	
	printf("Total track moment:%d",sum);
}
