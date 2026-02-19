#include <stdio.h>
#include <stdlib.h>

//Queue Structs
typedef struct node {
    int data;
    struct node *next;
} Node;

typedef struct {
    Node *front;
    Node *rear;
} Queue;

//Define functions
Queue *createQueue();
int QueueEmpty(Queue *q);
void enQueue(Queue *q, int key);
int deQueue(Queue *q);

int main(){
    //Variables
    int choice=0;
    int value=0;
    //Initialize Queue
    Queue * Q=createQueue();

    //Menu loop with switch for different actions
    while(1){
        printf("Menu:\n1. Enqueue\n2. Dequeue\n3. Print Queue\n4. Quit\nChoose an option:");
        scanf("%d",&choice);
        switch(choice){
            //Enqueue user inputted value
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                enQueue(Q, value);
                printf("Enqueued: %d\n",value);
                continue;
            //Delete the front
            case 2:
                int deleteValue=deQueue(Q);
                printf("Dequeued: %d\n", deleteValue);
                continue;
            //Print Queue
            case 3:
                printf("Queue: ");
                Node* current=Q->front;
                while(current!=NULL){
                    printf("%d ", current->data);
                    current=current->next;
                }
                printf("\n");
                continue;
            //Exit
            case 4:
                printf("Exiting program.\n");
                while(Q->front!=NULL){
                    current=Q->front;
                    Q->front=Q->front->next;
                    free(current);
                } 
                return 0;
            //Handle error
            default:
                printf("Invalid input.\n");
                continue;
        }
    }
    return 0;
}

//Create Queue (Initialize it with Null)
Queue *createQueue(){
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front=NULL;
    q->rear=NULL;
    return q;
}

//if the Queue is empty return true
int QueueEmpty(Queue *q){
    return (q->front==NULL);
}

//Enqueue by making a new node with new value (key)
void enQueue(Queue *q, int key){
    Node* newNode=NULL;
    newNode=(Node*)malloc(sizeof(Node));
    newNode->data=key;

    //If queue is empty make newNode rear and front
    if(QueueEmpty(q)==1){
        q->front=newNode;
        q->rear=newNode;
    }
    //Else add it to rear
    else{
        q->rear->next=newNode;
        q->rear=newNode;
    }
}

//Dequeue by deleting the front node and return it's value (key)
int deQueue(Queue *q){
    Node* deleteNode=q->front;
    int key=q->front->data;
    q->front=q->front->next;
    if(q->front==NULL){q->rear=NULL;}
    free(deleteNode);
    return key;
}
