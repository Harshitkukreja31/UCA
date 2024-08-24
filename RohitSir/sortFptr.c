#include <stdio.h>

void swap(int *a,int *b){
    int temp= *a;
    *a=*b;
    *b=temp;
}

void bubblesort(int arr[],int n,int (*compare)(int,int)){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(compare(arr[j],arr[j+1])){
                swap(&arr[j],&arr[j+1]);
            }
        }
    }
}

int ascending(int a,int b){
    return a>b;
}
int descending(int a,int b){
    return a<b;
}

void printarray(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main(){
    int arr[]={0,3,2,4,5,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    int choice;
    printf("Enter 0 for ascending sort, 1 for descending sort");
    scanf("%d",&choice);
    if(choice==0){
        bubblesort(arr,n,ascending);
    }
    else if(choice==1){
        bubblesort(arr,n,descending);
    }
    printarray(arr,n);
    return 0;
}