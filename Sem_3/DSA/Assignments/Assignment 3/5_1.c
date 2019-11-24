#include <stdio.h>
#include <stdlib.h>		//for dynamic memory allocation
#include <stdbool.h>


struct node
{
	int data;
	struct node *next;
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


bool atend_l(struct node **rehead, struct node *cur_node)
{
	int flag;
	flag=(cur_node==(*rehead));
	return flag;
}

void insert_front(struct node **rehead, int x)
{
	//allocate node
	struct node *newnode= (struct node*)malloc(sizeof(struct node));
	newnode->data= x;
	
	struct node *temp= *rehead;
	
	//Pointing the next pointer of the newnode to correct position
	newnode->next=(*rehead);
	
	//If linked list is not NULL, set the next of last node
	if(*rehead!=NULL)
	{
		while(temp->next !=*rehead)
			temp=temp->next;
		temp->next=newnode;
	}
	else
		newnode->next=newnode;
	
	*rehead=newnode;
}

void insertAfter(struct node *prev, int x)
{
	//Check if prev node is NULL
	if(prev==NULL)
	{
		printf("Cannot be find\n");
		return;
	}
	
	//allocate node
	struct node* newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=x;
	
	newnode->next=prev->next;
	prev->next=newnode;
}

void delete_front(struct node *rehead)
{
	struct node *current,*cur;
	current=rehead;
	cur=current;
	if(rehead==NULL)
	{
		printf("Cannot delete from empty list\n");
		return;
	}
	while(!atend_l(&rehead,cur)) cur=cur->next;
	printf("%d\n",cur->data);
	rehead=current->next;
	cur->next=rehead;
	current->next=NULL;
}

void deleteNode(struct node **rehead, int position) 
{ 
   if (*rehead == NULL) 
      return; 
  
   struct node* current = *rehead; 
  
    if (position == 1) 
    { 
        *rehead = current->next;   // Change head 
        free(current);               // free old head 
        return; 
    } 
  	int i;
    // Find previous node of the node to be deleted 
    for (i=1; current!=(*rehead) && i<=position-1; i++) 
         current = current->next; 
  
    // If position is more than number of nodes 
    if (current == *rehead || current->next == *rehead) 
         return; 
  
    // Node current->next is the node to be deleted 
    // Store pointer to the next of node to be deleted 
    struct node *next = current->next->next; 
  
    // Unlink the node from linked list 
    free(current->next);  // Free memory 
    current->next = next;  // Unlink the deleted node from list 
} 

void printlist(struct node *head)
{
	struct node *temp = head; 
    if (head != NULL) 
    { 
        do
        { 
            printf("%d ", temp->data); 
            temp = temp->next; 
        } 
        while (temp != head); 
    }
    printf("\n");
}

int main()
{
	struct node *HEAD=init_l();
	printf("SINGLY CIRCULAR LINKED LIST initialised\n");
	
	printf("Operations to be performed:\n");
	printf("PRESS 1 to check empty_l\n");
	printf("PRESS 2 to check current node pointing last\n");
	printf("PRESS 3 to insert a number in the front\n");
	printf("PRESS 4 to insert a number after a given position\n");
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
			{
				if(pos>k)
					break;
				current=current->next;
			}
			atend_l(&HEAD,current);
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
			{
				if(pos>k)
					break;
				current=current->next;
			}
			insertAfter(current,arr[k]);
			k++;
		}
		
		else if(ch==5)
		{
			delete_front(HEAD);
			k--;
		}
		else if(ch==6)
		{
			printf("\nEnter position:");
			scanf("%d",&pos);
			deleteNode(&HEAD,pos);
			k--;
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
