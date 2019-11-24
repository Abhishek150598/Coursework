//program to perform operations of linked list dynamically
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
struct node{//declaring structure to hold list items
	int data;//data field
	struct node* next;//next pointer
}*head,*cur;
typedef struct node NODE ;
typedef struct node * pnode ;
void createlist()//function for creating a list
{
	int i=1;
	while(i<=10)//list will initially have 10 elements
	{
		pnode new_node;//new node will hold each new nodes value
		new_node=(pnode)malloc(sizeof(NODE));//allocating memory for it
		new_node->data=rand()%100;//filling it with random values
		new_node->next=NULL;
	
		if(head==NULL)//if list is empty head is made last node
		{
		head=new_node;
		cur=new_node;
		}
		else//if list is not empty it is just appended at end
		{
			cur->next=new_node;
			cur=new_node;
		}
		i++;
	}
}
void delete_node(pnode start)//function to delete a node
{
	if(start==head)//if head node is to be deleted
	{
		head=start->next;
		free(start);
	}
	else if(start->next==NULL)//if it is last node
	{
		pnode before_start=head;
		while(before_start->next!=start)
		{
			before_start=before_start->next;
		}
		before_start->next=NULL;
		free(start);//deallocating memory
	}
	else//if it is a node in between
	{
		pnode iterate=head;//the next pointer of the node is adjusted for which the loop is run
		while(iterate->next!=start)
		{
			iterate=iterate->next;
		}
		iterate->next=start->next;
		free(start);
	}
	
}
void delete_list()//function to delete a list 
{
	pnode start=head,alternate;
	while(start!=NULL)
	{
		alternate=start;
		start=start->next;
		delete_node(alternate);//each node is deleted
	}
}
void search_key()//function to search a key in list
{
	pnode start=head;
	printf("enter key to search\n");
	int search_key;
	scanf("%d",&search_key);//search key is taken input
	while(start!=NULL)//finding element
	{if(start->data == search_key)
	  {printf("\nfound\n");//if found message is printed
	  delete_node(start);
	  return;
	  }
		start=start->next;
	}
	printf("\nNot found\n");//else print not found
}
void printlist()//printign whole list
{
	printf("\nprinting list\n");//printing whole list
	pnode start=head;
	while(start!=NULL)//till last element is reached
	{
		printf("%d\n",start->data);
	    start=start->next;//next element is incremented
	}
}
void reverse_print(pnode rev)//function to reverse print a lsit
{
	if(rev->next==NULL)
	{
	printf("%d\n",rev->data);//reverse data is printed
    return;
	}
	reverse_print(rev->next);
	printf("%d\n",rev->data);
	
}
void sortt()//function to sort a list
{
	int value;
	pnode node1,node2,node3;
	node1=head;
	//descending sort via selection sort is performed
	while(node1!=NULL)
	{
	
		node3=node1;
		value=node1->data;
		node2=node1->next;
		while(node2!=NULL)
		{
		
			if(node2->data>=value)//sorting in descending order
			{
				value=node2->data;
				node3=node2;
			}
		node2=node2->next;
		}
	//swapping data of nodes
	int temp=node1->data;
	node1->data=node3->data;
	node3->data=temp;
	  
	node1=node1->next;
	}
}

void delete_key()
{
	int del;
	printf("enter key to delete\n");
	scanf("%d",&del);
	pnode start=head;
	while(start!=NULL)
	{
		if(start->data==del)
		{
		delete_node(start);
		break;
		}
		else
		start=start->next;
	}
}
int find_length()//function to find length of list
{
	pnode start=head;
	int length=0;
	while(start!=NULL)
	{
		length++;//each node length is added
		start=start->next;
	}
	printf("length is %d\n",length);
	return length;//return of length
}
void last_to_front()//insert node from last to front
{
	pnode last;
	int value=head->data,prev;
	last=head->next;
	while(last!=NULL)//finding last node
	{
		prev=last->data;
		last->data=value;
		value=prev;
		last=last->next;
	}
	head->data=value;//head is changed to last node
}
void remove_duplicates()//function to remove  duplicates
{
	pnode start=head,finish;
	while(start!=NULL)//while end is not reached
	{
		finish=start->next;
		while(finish!=NULL)
		{
			if(finish->data==start->data)
			{
		    pnode delfinish=finish;
			finish=finish->next;
			delete_node(delfinish);
			continue;	
			}
			
		finish=finish->next;
		}
		
	start=start->next;
	}
}
void insert_node()//function to insert node
{
	pnode new_node=(pnode)malloc(sizeof(NODE));//allocating memory for new_node
	printf("enter data to insert\n");
	scanf("%d",&new_node->data);//taking input the dat to insert
	new_node->next=NULL;
	int position;
	printf("enter 1 to insert in the beginning of list\nenter 0 to insert at the end\nenter -1 to insert before a specified node\n");
	scanf("%d",&position);//taking input position to insert
	if(position==1)//beginni8ng oif list
	{
		new_node->next=head;
		head=new_node;
	}
	else if(position==0)//inserting at end
	{
		pnode start=head;
		while(start->next!=NULL)
		{
			start=start->next;
		}
		start->next=new_node;
	}
	else//insert in between of list
	{
		int value;
		printf("enter node data\n");
		scanf("%d",&value);
		pnode target,prev;
		target=head;
		while(target->data!=value)
		{
			prev=target;
			target=target->next;
		}
		prev->next=new_node;
		new_node->next=target;
	}
}
void del_alternate()//function to delete alternate nodes
{
	int i=0;
	pnode start=head;
	while(start!=NULL)
	{
		if(i%2!=0)
		{
			pnode del=start;
			start=start->next;
			delete_node(del);
			i++;
			continue;
		}
		i++;
	start=start->next;}
}
void swap_node()//function to swap nodes
{
	 int value1,value2,temp;
	 printf("enter value of first node\n");
	 scanf("%d",&value1);//taking input of first node
	 printf("enter value of second node\n");
	 scanf("%d",&value2);//taking input of 2nd node
	 pnode start=head,finish;
	 while(start!=NULL)
	 {
	 	if(start->data==value1)
	 	{
	 		finish=start->next;
	 		while(finish->data!=value2 && finish!=NULL)
	 		{
	 			finish=finish->next;
			}
			 temp=finish->data;
			 finish->data=start->data;
			 start->data=temp;
			 break;
			 
		 }
		 else if(start->data==value2 )
	 	{
	 		finish=start->next;
	 		while(finish->data!=value1 && finish!=NULL)
	 		{
	 			finish=finish->next;
			}
			//swapping data value sof both
			 temp=finish->data;
			 finish->data=start->data;
			 start->data=temp;
			 break;
		 }
	 	start=start->next;
	 }
}
void reverselist()//function to reverse a list
{
	pnode end=cur,start=head,aux=NULL;
	while(head!=end)
	{
		start=head;
		head=head->next;
		start->next=aux;
		cur->next=start;
		aux=start;
	}
}
int isascending()//sort in ascending order
{
	pnode start=head,after;
	while(start->next!=NULL)
	{
		after=start->next;
		if(after->data <= start->data)
		return 0;
		
	start=start->next;
	}
	return 1;
}
int isdescending()//sort in descending order
{
	pnode start=head,after;
	while(start->next!=NULL)
	{
		after=start->next;
		if(after->data >= start->data)
		return 0;
		
	start=start->next;
	}
	return 1;
}
void rotate_list()//function to rotate a list
{
	int rotate_count;
	printf("\nenter no. of elements to rotate by \n");
	scanf("%d",&rotate_count);//no. of elements to rotate after is taken is input
	int len=find_length();
	rotate_count=rotate_count % len ;
	rotate_count--;
	cur->next=head;
	while(rotate_count>0)
	{
		head=head->next;
		
		rotate_count--;
	}
	cur=head;
	head=head->next;
	cur->next=NULL;
}
void merge_list()//function to merge a lsit into another 
{
	printf("\nThe second list is \n");
	int i=1;
    pnode head1=NULL,cur1=NULL;
	while(i<=10)
	{
		pnode new_node;
		new_node=(pnode)malloc(sizeof(NODE));
		new_node->data=rand()%100;
		printf("%d ",new_node->data);
		new_node->next=NULL;
	
		if(head1==NULL)
		{
		head1=new_node;
		cur1=new_node;
		}
		else
		{
			cur1->next=new_node;
			cur1=new_node;
		}
		i++;
	}
	printf("\n");
	cur->next=head1;
	cur=cur1;
	
}
void merge_sort()//function two merge two sorted lists  
{
	
	printf("\nThe second list is \n");
	int i=1;
    pnode head1=NULL,cur1=NULL;
	while(i<=10)
	{
		pnode new_node;
		new_node=(pnode)malloc(sizeof(NODE));
		new_node->data=rand()%100;
		printf("%d ",new_node->data);
		new_node->next=NULL;
	
		if(head1==NULL)
		{
		head1=new_node;
		cur1=new_node;
		}
		else
		{
			cur1->next=new_node;
			cur1=new_node;
		}
		i++;
	}
	printf("\n");
	cur->next=head1;
	cur=cur1;
	sortt();
}
int main(void)
{
	int choice=1;
	head=NULL;
	srand(time(0));//creating random variables 
	createlist();
	printlist();
   //appropriate mesasages are displayed
	printf("enter 1 to find length of a list\nenter 2 to print a list\nenter 3 to reverse print a list\nenter 4 to delete key from list\nenter 5 to sort list\n");
	printf("enter 6 to move last element to front\nenter 7 to remove dupliicates\nenter 8 to insert a node\nenter 9 to delete alternate nodes\nenter 10 to swap \n");
    printf("enter 11 to reverse a list\nenter 12 to find sorting order\n");
    printf("enter 13 to search for a key in list\nenter 14 to delete a list\nenter 15 to rotate a list\nenter 16 to merge two lists\nenter 17 to merge sorted lists\n");
	while(choice!=0)//0 to exit
	{
	printf("enter 0 to exit\nenter choice \n");
	scanf("%d",&choice);
    switch(choice){
    	case 1:{
    		int len =find_length();//finding length
			break;
		}
		case 2:{
				printlist();//printing list
			break;
		}
		case 3:{
			 printf("reverse print \n");
				pnode rev=head;
				reverse_print(rev);//reverse prinitng
			break;
		}
		case 4:{	delete_key();//deleting key
         	printlist();
			break;
		}
		case 5:{
			printf("\nafter sorting\n");
            sortt();//sorting list
         	printlist();
			break;
		}
		case 6:{
			last_to_front();//last to fron addition
			printlist();
			break;
		}
		case 7:{
			remove_duplicates();//removing duplicates
			printf("after removing duplicates\n");
			printlist();
			break;
		}
		case 8:{
			insert_node();//inserting node
			printlist();	
			break;
		}
		case 9:{
			del_alternate();//delet alternate nodes
	       printlist();	
			break;
		}
		case 10:{
			swap_node();//swapping nodes
			printlist();
			break;
		}
		case 11:{
			reverselist();//reversing a list
			printlist();
			break;
		}
		case 12:{//checking sorting order
			if(isascending())
			printf("ascending\n");
			else if(isdescending())
			printf("descending\n");
			else
			printf("not sorted\n");
			break;
		}
		case 13:{
			search_key();//searching key
			break;
		}
		case 14:{
			delete_list();//deleting list
			break;
		}
		case 15:{
			rotate_list();//rotating list
			break;
		}
		case 16:{
			merge_list();//merging list
			break;
		}
		case 17:{
			merge_sort();//merge and sorting
			break;
		}
		case 0:{
		//exit
			break;
		}
	}
	
	}
}
