#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data; //Actual data on the node
    struct Node *next; //Pointer to next node on the list
} Node;

typedef struct {
    Node *first; //Pointer to the start of the list
    Node *last;  //Pointer to the end of the list
} List;

//Declare functions
void add(List *L, int value);
int find_max(List *L);

int main(){
    //Variables
    int listSize = 0;
    int element = 0;
    //Initialize the Linked List to null
    List *L = (List*)malloc(sizeof(List));
    L->first=NULL;
    L->last=NULL;
    //Ask user for size of List
    printf("Enter the number of integers: ");
    scanf("%d" ,&listSize);
    printf("Enter %d integers:\n", listSize);
    //Loop to get all elements
    for(int i=0;i<listSize;i++){
        scanf("%d", &element);
        add(L, element);
    }
    int max = find_max(L);
    printf("\nThe maximum value is: %d\n", max);

    //Free allocated memory
    Node* current = L->first;
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

void add(List *L, int value){
    //Allocate space for new node and change the next pointer to the new element
    Node* pNew;
    pNew = (Node*)malloc(sizeof(Node));
    pNew->data = value;
    pNew->next = L->first;
    L->first = pNew;
}

int find_max(List *L){
    //Iterate through the list to find largest int, then return it
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
