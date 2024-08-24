#include <stdio.h>

int add(int a,int b)
{
	return a+b;
}
int sub(int a,int b)
{
	return a-b;
}
int mul(int a,int b)
{
	return a*b;
}
int div(int a,int b)
{
	return a/b;
}
int mod(int a,int b)
{
	return a%b;
}

int main()
{
	int(*fptr[])(int,int)={add,sub,mul,div,mod};
	int a=2,b=3;
	int choice;
	scanf("Enter operation: %d",&choice);
	int ans=(*fptr[choice])(a,b);
	printf("ans: %d",ans);
	return 0;
}
