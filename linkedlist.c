#include <stdio.h>
#include <stdlib.h>

//Structs
typedef struct Node {
    int data; 
    struct Node *next; 
} Node;

typedef struct {
    Node *first; 
    Node *last;  
} List;

//Declare functions
List *createList();
void add(List *L, int value);
void reverse(List *L);
int find_max(List *L);

int main(){
    //Variables
    int listSize = 0;
    int element = 0;

    //Initialize
    List * L=createList();

    //User input
    printf("Enter the number of integers: ");
    scanf("%d" ,&listSize);
    printf("Enter %d integers:\n", listSize);
    for(int i=0;i<listSize;i++){
        scanf("%d", &element);add(L, element);
    }

    //Print original
    printf("\nOriginal list:");
    Node* current = L->first;
    int stack[200];
    int top=-1;

    while(current != NULL){
        stack[++top] = current->data;
        current=current->next;
    }
    while(top>=0){
        if(top==0){printf(" %d\n", stack[top--]);}
        else{printf(" %d ->",stack[top--]);}
    }

    //Reverse
    reverse(L);

    //Print reverse
    printf("Reversed list:");
    current=L->first;
    top=-1;

    while(current != NULL){
        stack[++top] = current->data;
        current=current->next;
    }
    while(top>=0){
        if(top==0){printf(" %d\n", stack[top--]);}
        else{printf(" %d ->",stack[top--]);}
    }

    //Print max
    int max = find_max(L);
    printf("The maximum value is: %d\n", max);

    //Free allocated memory
    current = L->first;
    Node* next;
    while (current != NULL)
    {
        next=current->next;
        free(current);
        current=next;
    }
    free(L);
    return 0;
}

//Create/Initialize List
List *createList(){
    List *L = (List*)malloc(sizeof(List));
    L->first=NULL;
    L->last=NULL;
    return L;
}

//Add new element to List
void add(List *L, int value){
    Node* pNew;
    pNew = (Node*)malloc(sizeof(Node));
    pNew->data = value;
    pNew->next = L->first;
    L->first = pNew;
}

//Reverse list
void reverse(List *L){
    //Check if empty or one element
    if(L->first==NULL || L->first==L->last){return;}
    //Reverse links
    Node* current = L->first;
    Node* previous = NULL;
    Node* next = NULL;
    while(current!=NULL){
        next=current->next;
        current->next=previous;
        previous=current;
        current=next;
    }
    //Change head<>tail
    next=L->first;
    L->first=previous;
    L->last=next;
}

//Find max value
int find_max(List *L){
    int max = 0;
    Node* current = L->first;
    while (current != L->last){
        if(current->data > max){
            max=current->data;
        }
        current = current->next;
    }
    return max;
}
