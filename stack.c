#include <stdio.h>
#include <stdlib.h>
*/void display();
void push();
void pop();*/
struct node {
	int data;
	struct node *next;
};
struct node *top = NULL;
void main() {
	int opt;
	do {
		printf("\nChoose the option number\n 1.Push, 2.Pop, 3.Display, 4.Exit : ");
		scanf("%d",&opt);
		switch(opt){
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				display();
				break;
			case 4:
			default:
				printf("\nEXIT\n");
				break;
		}
	} while (opt !=4);
}
void push() {
	struct node *new = NULL; 
	int n,i;
	printf("Enter the number of items to be added : ");
	scanf("%d",&n);
	for(i=0;i<n;i++) {
		new = (struct node*)malloc(sizeof(struct node));
		printf("Enter the data : ");
		scanf("%d",&new->data);
		new->next=top;
		top=new;
	}
}
void pop() {
	if(top == NULL) {
		printf("The stack is empty, underflow\n");
	}
	else {
		printf("The item %d is poped \n",top->data);
		struct node *ptr = top;
		top = top->next;
		free(ptr);
	}
}
void display() {
	if(top == NULL) {
		printf("The stack is empty, underflow\n");
	}
	else {
		printf("The Stack is : ");
		struct node *ptr = top;
		while(ptr!=NULL) {
			printf("%d ",ptr->data);
			ptr = ptr->next;
		}
		printf("\n");
	}
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
