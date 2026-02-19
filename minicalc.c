#include <stdio.h> 

#define SUM(a,b) (a+b)
#define DIF(a,b) (a-b)
#define MUL(a,b) (a*b)
#define DIV(a,b) (b!=0 ? a/b : 0)
#define EXP(a,b) power(a,b)
#define MOD(a,b) (b!=0 ? a%b : 0)

int power(int a, int b) {
    int r=1;
    for(int i = 0; i < a; i++) {r*=a;}
    return r;
}

int main(){
    int a,b,c;

    while(1){
        printf("\nMINICALC\n1.SUM\n2.DIF\n3.MUL\n4.DIV\n5.EXP\n6.MOD\n7.EXIT\nSELECT: ");
        scanf("%d", &c);
        if(c==7){printf("BYE!\n"); return 0;}
        printf("INPUT A&B\n");
        scanf("%d %d", &a,&b);
        switch(c){
            case 1:
                printf("SUM IS %d\n",SUM(a,b)); continue;
            case 2:
                printf("DIF IS %d\n",DIF(a,b)); continue;
            case 3:
                printf("MUL IS %d\n",MUL(a,b)); continue;
            case 4:
                printf("DIV IS %d\n",DIV(a,b)); continue;
            case 5:
                printf("EXP IS %d\n",EXP(a,b)); continue;
            case 6:
                printf("MOD IS %d\n",MOD(a,b)); continue;
            default:
                printf("INVALID INPUT\n");
        }
    }
}
