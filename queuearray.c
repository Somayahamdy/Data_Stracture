/****************************************************/
/*   AUTHOR      : Seif Al-dein Ahmed               */
/*   Description : Queue Array Based                */
/*   DATE        : 27 DEC 2021                      */
/*   VERSION     : V01                              */
/****************************************************/
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE    100

typedef struct queue
{
    int Arr[MAX_SIZE];
    int Front;
    int Rear;
    int size;
}Queue;

/***********************************/
/********Functions Prototypes*******/
/***********************************/
void Queue_voidInit(Queue* pq);
void Queue_voidEnQueue(int Copy_intValue, Queue* pq);
int  Queue_intIsFull(Queue* pq);
void Queue_voidDeQueue(Queue* pq, int* pd);
int  Queue_intIsEmpty(Queue* pq);
int  Queue_intSize(Queue* pq);
void Queue_voidPrint(Queue* pq);

int main()
{
    int FrontNode, size;
    Queue q;
    
    Queue_voidInit(&q);

    Queue_voidEnQueue(15, &q);
    Queue_voidEnQueue(8, &q);
    Queue_voidEnQueue(6, &q);

    Queue_voidPrint(&q);
    size = Queue_intSize(&q);
    printf("The size of Queue= %d\n", size);

    printf("======================\n");

    Queue_voidDeQueue(&q, &FrontNode);
    
    printf("%d\n", FrontNode);
    size = Queue_intSize(&q);
    printf("The size of Queue= %d\n", size);

    return 0;
}

void Queue_voidInit(Queue* pq)
{
    pq->Front = -1;
    pq->Rear = -1;
    pq->size = 0;
}

void Queue_voidEnQueue(int Copy_intValue, Queue* pq)
{
    if(Queue_intIsFull(pq))
    {
        printf("Queue is Full\n");
    }
    else
    {
        /*Check on Corner case: 1st EnQueue Operation*/
        if(pq->Front == -1)
        {
            /*Make Front holds the index of the first element in the Queue*/
            pq->Front = 0;
        }
        /*Make Rear holds the index of the location to be enQueued in*/
        pq->Rear++;
        /*Assign Value to this element*/
        pq->Arr[pq->Rear]= Copy_intValue;
        /*Increment size*/
        pq->size++;
    }
}

int  Queue_intIsFull(Queue* pq)
{
    return (pq->Rear == MAX_SIZE-1);
}

void Queue_voidDeQueue(Queue* pq, int* pd)
{
    if(Queue_intIsEmpty(pq))
    {
        printf("You Can't DeQueue, The Queue is Empty\n");
    }
    else
    {
        /*Return the Value of the Front Node to This pointer to data*/
        *pd = pq->Arr[pq->Front];
        /*Increment Front*/
        pq->Front++;
        /*Decrement Size*/
        pq->size--;
        /*Corner case: The last DeQueue Operation*/
        if(pq->Front > pq->Rear)
            pq->Front = pq->Rear = -1;  //Reset
    }
}

int Queue_intIsEmpty(Queue* pq)
{
    return (pq->Front == -1);
}

int  Queue_intSize(Queue* pq)
{
    return pq->size;
}

void Queue_voidPrint(Queue* pq)
{
    if(Queue_intIsEmpty(pq))
    {
        printf("You Can't Print, The Queue is Empty\n");
    }
    else
    {   
        for(int i = pq->Front; i <= pq->Rear; i++)
        {
            printf("%d\n", pq->Arr[i]);
        }
    }
}









