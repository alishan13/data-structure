#include <stdio.h>
#include <stdlib.h>

struct node {
	struct node *left;
	struct node *right;
	int data;
};

struct node *new=NULL,*ptr=NULL,*root=NULL, *leaf=NULL;
void insert();
void inorder(struct node*);
void preorder(struct node*);
void postorder(struct node*);
void search(struct node*);
struct node* leftMostLeaf(struct node* node);
void delete(struct node* root,struct node* parent, int key);

void main() {
	int opt,key;
	do {
		printf("\nChoose the operation number\n");
		printf("1.Insert \n2.Inorder-display \n3.Preorder-display \n4.Postorder-display \n5.Search \n6.Delete \n0.Exit : ");
		scanf("%d",&opt);
		switch(opt) {
			case 1: insert();
							break;
			case 2: inorder(root);
							break;
			case 3: preorder(root);
							break;
			case 4: postorder(root);
							break;
			case 5: search(root);
							break;
			case 6: printf("Enter the key : ");
							scanf("%d",&key);
							delete(root,root,key);
							break;
			case 0:
			default:break;
		}
	} while(opt!=0);
}

void insert() {
	new = (struct node*)malloc(sizeof(struct node));
	printf("Enter the data : ");
	scanf("%d",&new->data);
	new->left = new->right = NULL;
	if (new==NULL)
		printf("Insuffient memory");
	else {
		if (root == NULL)
			root = new;
		else {
			ptr = root;
			while(ptr!=NULL){
				if(new->data == ptr->data) {
					printf("Item already exists");
					break;
				}
				else if(new->data > ptr->data) {
					leaf = ptr;
					ptr=ptr->right;
				}
				else {
					leaf = ptr;
					ptr=ptr->left;
				}
			}
			if(new->data > leaf->data)
				leaf->right = new;
			else 
				leaf->left = new;
		}	
	}
}

void inorder(struct node *ptr){
	if(ptr!=NULL){
		inorder(ptr->left);
		printf("%d ",ptr->data);
		inorder(ptr->right);
	}
}

void preorder(struct node *ptr){
	if(ptr!=NULL){
		printf("%d ",ptr->data);
		preorder(ptr->left);
		preorder(ptr->right);
	}
}

void postorder(struct node *ptr){
	if(ptr!=NULL){
		postorder(ptr->left);
		postorder(ptr->right);
		printf("%d ",ptr->data);
	}
}

void search(struct node *ptr){
	int data,flag=0;
	if(ptr == NULL)
		printf("Empty tree");
	else {
		printf("Enter the element to find : ");
		scanf("%d",&data);
		while(ptr!=NULL){
			if(data == ptr->data){
				printf("Element found");
				ptr=NULL;
				flag=1;
			}
			else if(data > ptr->data)
				ptr=ptr->right;
			else
				ptr=ptr->left;
		}
		if(flag==0)
			printf("Element not found");
			
	}
}	

struct node* leftMostLeaf(struct node* node)
{
    struct node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

void delete(struct node* ptr,struct node* parent, int key)
{
    if (ptr == NULL)
	    printf("Empty tree or the key not found");
    else if (key < ptr->data)
        delete(ptr->left,ptr, key);
    else if (key > ptr->data)
        delete(ptr->right,ptr, key);
    else {
    		if(ptr->left==NULL && ptr->right ==NULL){
    			if(ptr==root){
    				root=NULL;
    				free(ptr);
    			}
    			else if(parent->left == ptr){
    				parent->left=NULL;
    				free(ptr);
    			}
    			else {
    				parent->right = NULL;
    				free(ptr);
    			}
					printf("Node deleted");
    		}
        else if(ptr->left == NULL) {
        	struct node* temp = ptr;
        	if(ptr==root){
        		root=ptr->right;
        		free(ptr);
        	} else {
            if(parent->left==ptr)
            	parent->left=ptr->right;
            else 
            	parent->right=ptr->right;
           	ptr=ptr->right;
            free(temp);
           }
					printf("Node deleted");
        }
        else if (ptr->right == NULL) {
        struct node* temp = ptr;
		      if(ptr==root){
		      		root=ptr->left;
		      		free(ptr);
		      	}
		      else {
						if(parent->left==ptr)
            	parent->left=ptr->left;
            else 
            	parent->right=ptr->left;
           	ptr=ptr->left;
            free(temp);
           }
					printf("Node deleted");
        }
       	else {
       		struct node* temp = leftMostLeaf(ptr->right);
       		ptr->data = temp->data;
       		delete(ptr->right,ptr,temp->data);
       	}
    }
}
