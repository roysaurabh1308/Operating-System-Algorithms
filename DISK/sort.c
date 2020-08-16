#include<stdio.h>
#include<conio.h>

void merge(int a[],int low,int mid,int high)
{
	int i=low,j=mid+1,k=low,c[high+1];
	while(i<=mid&&j<=high)
	{
		if(a[i]<=a[j])
		{
			c[k]=a[i];
			i++;
			k++;
		}
		else
		{
			c[k]=a[j];
			j++;
			k++;
		}
	}
	
	while(i<=mid)
	{
		c[k]=a[i];
		i++;
		k++;
	}
	while(j<=high)
	{
		c[k]=a[j];
		j++;
		k++;
	}
	
	for(i=low;i<high+1;i++)
	a[i]=c[i];
}

void ms(int a[],int low,int high)
{
	int mid;
	if(low<high)
	{
		mid=(low+high)/2;
		ms(a,low,mid);
		ms(a,mid+1,high);
		merge(a,low,mid,high);
	}
}
