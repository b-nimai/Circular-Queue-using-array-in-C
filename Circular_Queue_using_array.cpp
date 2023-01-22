#include <stdio.h>

#define N 5

int front = -1, rear = -1;
int queue[N];

void enqueue()
{
    int data;
    printf("\tEnter the data that you wants to enque: ");
    scanf("%d",&data);
    if((rear + 1)%N == front)
    {
        printf("\tThe queue is already full"); 
    }
    else if(front == -1 && rear == -1)
    {
        front++;
        rear++;
        queue[rear] = data;
    }
    else
    {
        rear = (rear + 1) % N;
        queue[rear] = data;
    }
}

void dequeue()
{
    if(front == -1 && rear == -1)
    {
        printf("\tThe queue is already empty.");
    }
    else if(front == rear)
    {
        printf("\tThe dequeue element is: %d",queue[front]);
        front = rear = -1;
    }
    else
    {
        printf("\tThe dequeue element is: %d",queue[front]);
        front = (front + 1) % N;
    }
}


void peak()
{
    if(front == -1 && rear == -1)
    {
        printf("\tThe queue is empty.");
    }
    else
    {
        printf("\tThe peak of the queue is: %d",queue[front]);
    }
}


void display()
{
    int i;
    i = front;
    if(front == -1 && rear == -1)
    {
        printf("\tThe queue is empty.");
    }
    else
    {
        printf("\tThe elements of the queue are: ");
        while(i != rear)
        {
            printf("%d\t", queue[i]);
            i = (i + 1)%N;
        }
        printf("%d",queue[rear]);
    }
}
/*
void display()
{
    int i;
    if(front == -1 && rear == -1)
    {
        printf("\tThe queue is empty.");
        return;
    }
    printf("\n\tThe elements of the circular queue are : ");
    if(front<=rear)
    {
        for(i=front;i<rear + 1;i++)
        printf(" %d ",queue[i]);
    }
    else
     {
        for(i=front;i<N+1;i++)
        printf(" %d ",queue[i]);
        for(i=0;i<rear+1;i++)
        printf(" %d ",queue[i]);
    }
}*/

int main()
{
    int choice;
    printf("\n\n******************This is the program of queue operation.*********************");
    do
    {
        printf("\n\n\t..................................................\n\tPlease enter the index of the operation to do that operation.\n\n\t\t1.Enqueue\n\t\t2.Dequeue\n\t\t3.Peak\n\t\t4.Display\n\t\t0.Exit\n\n\tEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 0:
            printf("\tProgram is ended.");
            break;

            case 1:
            enqueue();
            break;

            case 2:
            dequeue();
            break;

            case 3:
            peak();
            break;

            case 4:
            display();
            break;

            default:
            printf("\tPlease enter correct index.");
        }
    } while (choice != 0);
    
}