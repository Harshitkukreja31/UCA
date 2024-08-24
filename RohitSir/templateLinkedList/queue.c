#include "list.h"


void push(int* arr,int n,int data){
	arr[n]=data;
}
int pop(int* arr,int n)
{
	int val=arr[n-1];
	arr[n-1]=0;
	return val;
}
