#include<stdio.h>
#include<stdlib.h>
#define MAX 50

typedef struct queue
{
    int *array;
    int front,rear;
}queue;

queue *create_queue()
{
    queue *q = (queue*)malloc(sizeof(queue));
    q->front = -1;
    q->rear = -1;
    q->array = (int*)malloc(sizeof(int)*MAX);
    return q;

}

void enqueue (queue *q, int data) //Inserting into the queue
{
    q->front = 0;
    q->rear++;
    q->array[q->rear] = data;
}

void dequeue (queue *q) // Removing from the queue
{
    if(q->front == q->rear)
    {
        q->rear = q->front = -1;

    }
    if(q->rear == -1)
    {
        printf ("\nQUEUE EMPTY\n");
    }
    else
    {
        printf("\nElement %d removed", q->array[q->front]);
        q->front++;
    }
}

void display (queue *q)
{
    int i;
    if(q->rear == -1)
    {
        return;
    }
    printf ("\nThe Queue displayed from rear to front is:\n");
    for (i = q->rear; i >= q->front; i--)
    {
        printf ("%d ", q->array[i]);
    }
}

void main ()
{
    //Sample outputs
    queue *q = create_queue();
    enqueue(q,5);
    display(q);
    enqueue(q,10);
    enqueue(q,15);
    enqueue(q,20);
    enqueue(q,25);
    display(q);
    dequeue(q);
    display(q);
    dequeue(q);
    display(q);
    dequeue(q);
    display(q);
    dequeue(q);
    display(q);
    dequeue(q);
    display(q);
    dequeue(q);
    display(q);
}


