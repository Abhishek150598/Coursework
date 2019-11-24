//program to implement linked list by arrays
#include<stdio.h>
#include<time.h>
struct node
{//declaring structure node
	int data;
	int next;
	int empty;
};
typedef struct node NODE;
int max_length,head=0,tail;
void createlist(NODE list[])//function to create node and fill list
{
	int loop;
	for(loop=0;loop<10;loop++)
	{
		list[loop].data=rand()%100;//filling in random values
		list[loop].empty=0;
		list[loop].next=loop+1;
	}
	for(loop=10;loop<max_length;loop++) list[loop].empty=1;
	list[9].next=-1;
	tail=9;
}
void printlist(NODE list[])//function to print list
{
	int loop=0;
	printf("The list is\n");
	while(loop<max_length)
	{
	    printf("%d\n",list[loop].data);//printing value
		
		if(list[loop].next==-1)
		break;
		loop=list[loop].next;//next node is pointe dto
	}
}
void reverseprint(NODE list[],int index)//function to reverseprint a list
{
	if(list[index].next==-1)
	{
	printf("%d\n",list[index].data);
	return;	
	}
	reverseprint(list,list[index].next);
	printf("%d\n",list[index].data);
}
void delkey(NODE list[],int del)//function to delete key
{
	int loop=head,prev;

	while(loop<max_length)
	{
		if(list[loop].data==del)
		{
			if(loop==head)
			{
				list[loop].empty=1;
				head=list[loop].next;break;
			}
			else
			{
				if(loop==tail)
				tail=prev;
				list[loop].empty=1;
				list[prev].next=list[loop].next;break;
				
			}
		}
		prev=loop;
		loop=list[loop].next;
	}
}
void sort(NODE list[])//function to sort a list
{//selection sort for ascending sort
	int loop1=head,temp,pos,loop2;
	while(loop1!=tail)
	{
		pos=loop1;
		loop2=list[loop1].next;
		while(loop2!=-1)
		{
			if(list[loop2].data<=list[pos].data)
			pos=loop2;
			
	loop2=list[loop2].next;	}
	
		temp=list[loop1].data;
		list[loop1].data=list[pos].data;
		list[pos].data=temp;
		
	loop1=list[loop1].next;}
}
void last_to_front(NODE list[])//function to sshift last element to front
{
	int loop=head,prev;
	while(loop<max_length)
	{
		if(list[loop].next==-1)
		break;
		
		prev=loop;
		loop=list[loop].next;
	}
	list[prev].next=-1;
	tail=prev;
	list[loop].next=head;
	head=loop;
	
}

void removeduplicates(NODE list[])//function to remove duplicates
{
	int loop=head,alt;
	while(list[loop].next!=-1)
	{   alt=list[loop].next;
		while(list[alt].next!=-1)
		{
			if(list[loop].data==list[alt].data)
			{
				alt=list[alt].next;
				delkey(list,list[loop].data);
				continue;
			}
	alt=list[alt].next;
	    }
	loop=list[loop].next;
	}
}

void delete_alternate(NODE list[])//function to delet alternate node
{
	int loop=0,i=0;
	while(i<max_length)
	{
		if(list[i].next==-1)
		break;
		
		if(i%2!=0)
		{
			delkey(list,list[i].data);//deleting node
		}
		
	i++;}
}
void insert(NODE list[])//function to insert node in list
{
	int value,position,index=0;
	printf("enter data to insert\n");
	scanf("%d",&value);//taking input data to insert
	printf("enter 1 to insert in the beginning of list\nenter 0 to insert at the end\nenter -1 to insert before a specified node\n");
	scanf("%d",&position);//position to insert
	while(index<max_length)
	{
		if(list[index].empty==1)
		break;
		
		index++;
	}
	printf("%d\n",index);
	list[index].empty=0;
	list[index].data=value;
	if(position==1){//beginning
	
	list[index].next=head;
	head=index;
    }
    else if(position==0)//end at list
    {
    list[index].next=-1;
    list[tail].next=index;
    tail=index;
	}
	else
	{
	  int place,lp=0,lp1=lp+1;
	  printf("enter node before which value has to be inserted");
	  scanf("%d",&place);
	while(lp<max_length)
	{
		  if(list[lp1].data==place)
		  {
		  	list[index].next=lp1;
			list[lp].next=index;
			break;
			}
			lp=lp1;
			lp1++;
	}
	}
}
void swap_node(NODE list[])//function to swap node
{
	int first,second;
	printf("\n enter value of first node\n");
	scanf("%d",&first);//taking input value of 1st node
	printf("\n enter value of second node\n");
    scanf("%d",&second);//taking iput 2nd node value
    
    int loop=head,pos1,pos2;
    while(loop<max_length)
	{
       if(list[loop].data == first)
	   pos1=loop;	  
	   if(list[loop].data == second)
	   pos2=loop;	  
			
		if(list[loop].next==-1)
		break;
		loop=list[loop].next;
	}
	//swapping nodes
	int temp=list[pos1].data;
	list[pos1].data=list[pos2].data;
	list[pos2].data =temp;
}
void reverse_list(NODE list[])//function to reverse a list
{
	int loop=head,limit=find_length(list);
	
	for(;loop<(limit/2);loop++)
	{
		int pos1=loop,pos2=limit-loop-1;
		int temp=list[pos1].data;
	    list[pos1].data=list[pos2].data;
	    list[pos2].data =temp;
	}
}
int find_length(NODE list[])//fnctioj to find length of a list
{int loop=0,length=0;
	 while(loop<max_length)
	{length++;
       		
		if(list[loop].next==-1)
		break;
		loop=list[loop].next;
	}
	return length;
}
void sorting_order(NODE list[])//function to find soring order of list
{
	int alen=find_length(list)-1;
	int dlen=alen;
	int loop=0;
	while(loop<max_length)
	{   if(list[loop].next==-1)
		break;
		
		if(list[loop].data>list[loop+1].data)
		dlen--;
		else
		alen--;
       		

		loop=list[loop].next;
	}
	if(dlen==0)
	printf("descending\n");
	else if(alen==0)
    printf("ascending\n");
    else
    printf("not sorted\n");
}
void search_key(NODE list[])//function to search for a key in list
{
	int loop=head,search;
	printf("\nenter search element\n");
	scanf("%d",&search);
	while(loop<max_length)
	{   if(list[loop].data == search)
	    {
	    	printf("\nfound\n");return;
		}
       		
		if(list[loop].next==-1)
		break;
		loop=list[loop].next;
	}
	printf("\nNot Found\n");
}
void deletelist(NODE list[])//function to delete a list
{
	list[head].next=-1;
}
void merge_list(NODE list[])//function to merge and sort two list
{
	int loop=0;
	while(loop<max_length)
	{   
	    if(list[loop].next==-1)
		break;
		loop=list[loop].next;
	}
	list[loop].next=loop+1;
	loop++;
	int limit=loop+10;
	printf("\nThe 2nd list is\n");
	for(;loop<limit;loop++)
	{
		list[loop].data=rand()%100;
		printf("%d ",list[loop].data);
		list[loop].empty=0;
		list[loop].next=loop+1;
	}
	printf("\n");
	loop=loop-1;
	list[loop].next=-1;
	tail=loop;
}
int main(void)
{
	head=0;
	int choice=1,del;
	printf("enter maximum no. of elements \n");//taking input maximum no. of elemnts
	scanf("%d",&max_length);
	srand(time(0));
	NODE list[max_length];//array of nodes is declared  
	//necessary options are given to user
	printf("enter 1 to create a list\nenter 2 to print a list\nenter 3 to reverse print a list\nenter 4 to delete key from list\nenter 5 to sort list\n");
	printf("enter 6 to move last element to front\nenter 7 to remove dupliicates\nenter 8 to insert a node\nenter 9 to delete alternate nodes\nenter 10 to swap \n");
    printf("enter 11 to reverse a list\nenter 12 to find sorting order\nenter 13 to find length of a list\nenetr 14 to search for element in list\n");
    printf("enter 15 to delete list\nenter 16 to merge two lists\n");
	while(choice!=0)
	{
	printf("enter choice\n");
	scanf("%d",&choice);
    switch(choice)
	{
	case 1:{
		createlist(list);//creating a list
		break;
	}
	case 2:{
		printlist(list);//prining a list
		break;
	}
	case 3:{
	    printf("reverse print\n");
		reverseprint(list,head);//rverse printign a list
		break;
	}
	case 4:{
        	printf("enter key to delete\n");//deleting a list
	scanf("%d",&del);
		delkey(list,del);		
		break;
	}
	case 5:{
		sort(list);//sorting a list
		break;
	}
	case 6:{
		last_to_front(list);//move last to front
		break;
	}
	case 7:{
		removeduplicates(list);//removing duplicats
		break;
	}
	case 8:{
		insert(list);//inserting elemts
		break;
	}
	case 9:{
		delete_alternate(list);//delete alternates
		break;
	}
	case 10:{
		swap_node(list);//swapping nodes
		break;
	}
	case 11:{
		reverse_list(list);//reversi ng a list
		break;
	}
	case 12:{
	    sorting_order(list);//find sorting order
		break;
	}
	case 13:{
		printf("%d\n",find_length(list));
		break;
	}
	case 14:{
		search_key(list);//searching a key
		break;
	}
	case 15:{
		deletelist(list);//delet list
		break;
	}
	case 16:{
		merge_list(list);//append list
		break;
	}
	case 0:{
		
		break;
	}
	}








}
}
