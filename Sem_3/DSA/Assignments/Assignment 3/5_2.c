#include <stdio.h>
#include <stdlib.h>		//for dynamic memory allocation
#include <stdbool.h>


struct node
{
	int data;
	struct node *next;
	struct node *prev;
};


struct node* init_l()
{
	struct node *HEAD=NULL;
	return HEAD;
}


bool empty_l(struct node **rehead)
{
	int flag;
	flag=(*rehead==NULL);
	if(flag==0)
		printf("List is not empty\n");
	else
		printf("List is empty\n");
}


bool atend_l(struct node *cur_node)
{
	int flag;
	flag=(cur_node==NULL);
	if(flag==0)
		printf("Current is not pointing to last node\n");
	else
		printf("Current is pointing to last node\n");
}

void insert_front(struct node **rehead, int x)
{
	//allocate node
	struct node *newnode= (struct node*)malloc(sizeof(struct node));
	newnode->data= x;		
	
	//Pointing the next pointer and previous pointer of the newnode to correct position
	newnode->next=(*rehead);
	newnode->prev=NULL;
	
	
	if(*rehead !=NULL)
		(*rehead)->prev=newnode;
		
	*rehead=newnode;
}

void insertAfter(struct node *prev_given, int x)
{
	//Check if prev node is NULL
	if(prev_given==NULL)
	{
		printf("previous_given node cannot be null\n");
		return;
	}
	
	//allocate node
	struct node* newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=x;
	
	newnode->next=prev_given->next;
	prev_given->next=newnode;
	newnode->prev=prev_given;
	
	//Change previous of (newnode's next node)
	if(newnode->next!=NULL)
		newnode->next->prev=newnode;
}


void delete_front(struct node **rehead)
{
	struct node *current=*rehead;
	
	if(*rehead==NULL)
	{
		printf("Cannot delete from empty list\n");
		return;
	}
	
	*rehead=current->next;
	
	if (current->next != NULL) 
        current->next->prev = NULL; 
  
	free(current);
	return;
}

void deletenode(struct node** rehead, struct node* del) 
{ 
    if (*rehead == NULL || del == NULL) 
        return; 
  
    /* If node to be deleted is head node */
    if (*rehead == del) 
        *rehead = del->next; 
    /* Change next only if node to be deleted 
       is NOT the last node */
    if (del->next != NULL) 
        del->next->prev = del->prev; 
  
    /* Change prev only if node to be deleted  
       is NOT the first node */
    if (del->prev != NULL) 
        del->prev->next = del->next; 
  
    /* Finally, free the memory occupied by del*/
    free(del); 
}

void printlist(struct node *head)
{
	struct node *last;
	printf("\nTravesal in forward direction\n");
	while(head!=NULL)
	{
		printf("%d ",head->data);
		last=head;
		head=head->next;
	}
	
	/*
	printf("\nTravesal in backward direction\n");
	while(last!=NULL)
	{
		printf("%d ",last->data);
		last=last->prev;
	}
	*/
	
	printf("\n");
}

int main()
{
	struct node *HEAD=init_l();
	printf("DOUBLY LINKED LIST initialised\n");
	
	printf("Operations to be performed:\n");
	printf("PRESS 1 to check empty_l\n");
	printf("PRESS 2 to check current node pointing last\n");
	printf("PRESS 3 to insert a number in the front\n");
	printf("PRESS 4 to insert a number at the last\n");
	printf("PRESS 5 to delete a number in the front\n");
	printf("PRESS 6 to delete a node after a given node(position)\n");
	printf("PRESS 7 to print the linked list\n\n");
	printf("TO EXIT ENTER ANY OTHER NUMBER\n\n");
	
	//printf("Enter the number of operations to be performed\n");
	int n,i,j,ch,k,pos;
	//scanf("%d",&n);
	
	k=1;
	int arr[100];
	//struct node *current=HEAD;
	while(1)
	{
		printf("\nEnter choice for operation to perform:");
		scanf("%d",&ch);
		if(ch==1)
			empty_l(&HEAD);
		
		else if(ch==2)
		{
			printf("\nEnter position:");
			scanf("%d",&pos);
			struct node *current=HEAD;
			for(j=1; j<=pos; j++)
				current=current->next;
			atend_l(current);
		}
		else if(ch==3)
		{
			printf("\nEnter number:");
			scanf("%d",&arr[k]);
			insert_front(&HEAD,arr[k]);
			k++;
		}
		
		else if(ch==4)
		{
			printf("\nEnter number:");
			scanf("%d",&arr[k]);
			printf("\nEnter position:");
			scanf("%d",&pos);
			struct node *current=HEAD;
			for(j=1; j<pos; j++)
				current=current->next;
			insertAfter(current,arr[k]);
			k++;
		}
		
		else if(ch==5)
			delete_front(&HEAD);
		
		else if(ch==6)
		{
			printf("\nEnter position:");
			scanf("%d",&pos);
			struct node *current=HEAD;
			for(j=1; j<pos; j++)
				current=current->next;
			deletenode(&HEAD,current);
		}
		
		else if(ch==7)
			printlist(HEAD);
		
		else
		{
			printf("BYE!!\n");
			break;
		}
	}
	
	return 0;
}

