// Implement stack using array

#include <stdio.h>
#include <stdlib.h>

int size = 5, top = -1, a[5];

void push()
{
  int data;
  if (top == size - 1)
    printf("Stack overflow!\n");
  else
  {
    printf("Enter the data : ");
    scanf("%d", &data);
    if (top == -1)
      top = 0;
    else
      top++;
    a[top] = data;
    printf("item pushed\n");
  }
}

void pop()
{
  if (top == -1)
    printf("Empty Stack\n");
  else
  {
    top--;
    printf("item poped\n");
  }
}

void display()
{
  int i;
  if (top == -1)
    printf("Stack Empty");
  else
  {
    for (i = top; i > -1; i--)
      printf("%d ", a[i]);
  }
  printf("\n");
}

void main()
{
  int opt = 1;
  while (opt != 0)
  {
    printf("1.Push 2.Pop 3.Display 0.Exit");
    printf("\nChoose the operation :");
    scanf("%d", &opt);
    switch (opt)
    {
    case 1:
      push();
      break;
    case 2:
      pop();
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