// Queue implementation using Linked list

#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node *next;
};

struct node *top = NULL, *rear = NULL;

void enqueue()
{
  struct node *new = (struct node *)malloc(sizeof(struct node));
  if (new == NULL)
    printf("Insuffient memory \n");
  else
    printf("Enter the data : ");
  scanf("%d", &new->data);
  new->next = NULL;
  if (top == NULL)
    top = rear = new;
  else
  {
    rear->next = new;
    rear = new;
  }
  printf("item Added \n");
}

void dequeue()
{
  if (top == NULL)
    printf("Empty queue \n");
  else
  {
    if (top == rear)
      top = rear = NULL;
    else
      top = top->next;
    printf("item deleted \n");
  }
}

void display()
{
  struct node *ptr = top;
  if (top == NULL)
    printf("Empty queue \n");
  else
  {
    while (ptr != NULL)
    {
      printf("%d ", ptr->data);
      ptr = ptr->next;
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