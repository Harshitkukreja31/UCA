#include <stdio.h>
#include <stdlib.h>

void merge(int arr[],int l,int m,int r)
{
	int i,j,k,B[100];
	i=l;
	j=m+1;
	k=l;
	while(i<=m && j<=r)
	{
		if(arr[i]<arr[j]){
			B[k]=arr[i];
			i++;
			k++;
		}
		else{
			B[k]=arr[j];
			k++;
			j++;
		}
	}
	while(i<=m){
		B[k]=arr[i];
		k++;
		i++;
	}
	while(j<=r){
		B[k]=arr[j];
		k++;
		j++;
	}
	for(int i=l;i<=r;i++){
		arr[i]=B[i];
	}
}

void mergesort(int arr[],int l,int r)
{
	if(l<r){
		int m=l+(r-l)/2;

		mergesort(arr,l,m);
		mergesort(arr,m+1,r);
		merge(arr,l,m,r);
	}
}


void printarray(int arr[],int size)
{
	for(int i=0;i<size;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}

int main()
{
	int arr[]={12,11,13,5,6,7};
	int size=sizeof(arr)/sizeof(arr[0]);
	printarray(arr,size);
	mergesort(arr,0,size-1);
	printarray(arr,size);
	return 0;
}
