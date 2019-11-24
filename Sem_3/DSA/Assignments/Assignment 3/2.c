#include <stdio.h>
#include <stdlib.h>
struct node
{
	int info;
	struct node *next;
};

struct node *head1,*head2,*ptr1,*ptr2,*nxt1,*nxt2;

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
	FILE *fp;int val;
	fp=fopen("integer.txt","r");
	fscanf(fp,"%d\n",&val);
	head1=createnode(val);head2=createnode(val);
	ptr1=head1;
	while(!feof(fp))
	{
		fscanf(fp,"%d\n",&val);
		nxt1=createnode(val);
		nxt2=createnode(val);
		insert_after(nxt1,ptr1);
		ptr1=ptr1->next;
		insert_front(nxt2,&head2);
	}
	fclose(fp);
	ptr1=head1;ptr2=head2;
	printf("\n\nPRINTING IN GIVEN ORDER\n\n");
	while(ptr1!=NULL)
	{
		printf("%d\n",ptr1->info);
		ptr1=ptr1->next;
	}
	printf("\n\nPRINTING IN REVERSE ORDER\n\n");
	while(ptr2!=NULL)
	{
		printf("%d\n",ptr2->info);
		ptr2=ptr2->next;
	}
}
