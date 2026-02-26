#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void bubblesort( int arr[], const size_t n ){
    bool swapped;
    for (int i=0; i<n-1;i++){ 
        swapped=false;
        for (int j=0;j<n-1-i;j++){ 
            if (arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                swapped=true;
            }
        }
        if (!swapped){
            break;
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

    bubblesort(arr,size);
    
    printf("Sorted list\n");
    printlist(arr,size);
    return 0;
}
