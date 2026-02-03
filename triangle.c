#include <stdio.h>

int main(){
    int height;
    printf("Enter triangle height: ");
    scanf("%d",&height);
    char tree[height];

    for (int i=0; i<height; i++){
        tree[i]=' ';
    }

    for (int j=1; j<height+1; j++){
        tree[height-j]='*';
        printf("%.*s\n",height, tree);
    }
    return 0;
}