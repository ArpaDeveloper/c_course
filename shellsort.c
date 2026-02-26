#include <stdio.h>
#include <stdlib.h>

void shellsort(int arr[], const size_t size){

    for(int gap=size/2;gap>0;gap/=2){
        if(gap==1){
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
        else{
            for(int i=gap;i<size;i++){
                int x=arr[i];
                int j=i-gap;
                while(j>=0 && arr[j]>x){
                    arr[j+gap]=arr[j];
                    j-=gap;
                }
                arr[j+gap]=x;
            }
        }
    }
}

void printlist(int arr[], const size_t size){
    for(int i=0;i<size;i++){printf("%d ",arr[i]);}printf("\n");
}

int main(){
    int arr[]={54,22,77,18,45,98};
    size_t size=sizeof(arr)/sizeof(arr[0]);

    printf("Unsorted list\n");
    printlist(arr,size);

    shellsort(arr,size);
    
    printf("Sorted list\n");
    printlist(arr,size);
    return 0;
}