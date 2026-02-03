#include <stdio.h>
#include <stdbool.h>

void BubbleSort( int ai[], const size_t n ){
    bool swapped;
    for (int i=0; i<n-1;i++){ 
        swapped=false;
        for (int j=0;j<n-1-i;j++){ 
            if (ai[j]>ai[j+1]){
                int temp = ai[j];
                ai[j]=ai[j+1];
                ai[j+1]=temp;
                swapped=true;
            }
        }
        if (!swapped){
            break;
        }
    }  
}
