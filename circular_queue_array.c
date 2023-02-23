// impliment circular queue using array

#include <stdio.h>
#include <stdlib.h>

int a[5], size = 5, front = -1, rear = -1;

void enqueue()
{
  int data;
  if (front == (rear + 1) % size)
    printf("Queue is full \n");
  else
  {
    printf("Enter the data: ");
    scanf("%d", &data);
    if (front == -1)
      front = rear = 0;
    else
      rear = (rear + 1) % size;
    a[rear] = data;
    printf("Item added \n");
  }
}

void dequeue()
{
  if (front == -1)
    printf("Empty queue \n");
  else
  {
    if (rear == front)
      rear = front = -1;
    else
      front = (front + 1) % size;
    printf("Item deleted \n")
  }
}

void display()
{
  int temp = front, i;
  if (front == -1)
    printf("Empty queue \n");
  else
  {
    while (temp > -1)
    {
      printf("%d ", a[temp]);
      if (temp == rear)
        break;
      temp = (temp + 1) % size;
    }
    printf("\n");
  }
}

void main()
{
  int opt = 1;
  while (opt != 0)
  {
    printf("1.Enqueue 2.Dequeue 3.Display 0.Exit");
    printf("\nChoose the operation :");
    scanf("%d", &opt);
    switch (opt)
    {
    case 1:
      enqueue();
      break;
    case 2:
      dequeue();
      break;
    case 3:
      display();
      break;
    case 0:
    default:
      break;
    }
  }
}