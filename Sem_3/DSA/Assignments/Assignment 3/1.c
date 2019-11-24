#include <stdio.h>
#include <stdlib.h>
struct node
{
	int info;
	struct node *next;
};

struct node *head,*ptr,*nxt;

void init_l(struct node *cur)
{
	cur=NULL;
}
int atend(struct node *cur)
{
	if(cur->next==NULL) return 1;
	else return 0;
}
struct node *createnode(int item)
{
	struct node *a=NULL;
	if((a=(struct node*)malloc(sizeof(struct node)))==NULL) printf("\nmalloc error\n");
	else {a->info=item;a->next=NULL;}
	return (a);
}

void insert_after(struct node *target,struct node *prev)
{
	struct node *c;
	c=prev->next;
	target->next=c;
	prev->next=target;
}
void insert_front(struct node *target,struct node **p_head)
{
	target->next=*p_head;
	*p_head=target;
}
void delete_front(struct node **phead)
{
	struct node *cur;
	cur=*phead;
	*phead=cur->next;
	cur->next=NULL;
}
void delete_after(struct node *prev)
{
	struct node *cur;
	cur=prev->next;
	prev->next=cur->next;
	cur->next=NULL;
}
int main()
{
	int i,val;	
	init_l(head);
	scanf("%d",&val);
	head=createnode(val);
	ptr=head;
	//FOR INSERTING AFTER//
	while(scanf("%d",&val))
	{
		
		nxt=createnode(val);
		insert_after(nxt,ptr);
		ptr=ptr->next;
	}
	//FOR INSERTING BEFORE//
	/*while((scanf("%d",&val)))
	{
		nxt=createnode(val);
		insert_front(nxt,&head);
	}*/
	ptr=head;
	while(ptr!=NULL)
	{
		printf("%d\n",ptr->info);
		ptr=ptr->next;
	}
	printf("\n\n");
	//delete_front(&head);
	delete_after(head);
	ptr=head;
	while(ptr!=NULL)
	{
		//if(atend(ptr)) printf("\nAt end : ");
		printf("%d\n",ptr->info);
		ptr=ptr->next;
	}
	return 0;	
} 
