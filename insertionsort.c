#include <stdio.h>
#include <stdlib.h>

void insertionsort(int arr[], size_t size){
    for(int i=1;i<size;i++){
        int x=arr[i];
        int j=i-1;
        while(j>=0 && arr[j] > x){
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=x;
    }
}

int main(){
    int arr[]={54,22,77,18,45,98};
    size_t size=sizeof(arr)/sizeof(arr[0]);
    insertionsort(arr,size);
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}