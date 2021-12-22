#include<stdio.h>
#include<stdlib.h>

struct slist
{
	int data;
	struct slist *next;
};

typedef struct slist node;

node *create(node *first)
{
	int x;
	node *ne,*prev;
	printf("enter data(enter -1 to stop)\n");
	scanf("%d",&x);
	while(x!=-1)
	{
		ne=(node*)malloc(sizeof(node));
		ne->data=x;
		ne->next=NULL;
		if(first==NULL)
		{
			first=ne;
			prev=ne;
		}
		else
		{
			prev->next=ne;
			prev=ne;
		}
		printf("enter data(enter -1 to stop)\n");
		scanf("%d",&x);
	}
	return first;
}

void display(node *first)
{
	node *temp=first;
	if(first==NULL)
	{
		printf("no elements in the list to print");
	}
	else
	{
		while(temp!=NULL)
		{
			printf("|%d|->",temp->data);
			temp=temp->next;
		}
		printf("NULL");
	}
}

int count(node *first)
{
	int c=0;
	node *temp=first;
	if(first==NULL)
	{
		printf("no elements in the given linked list\n");
	}
	else
	{
		do
		{
			c++;
			temp=temp->next;
		}while(temp!=NULL);
	}
	return c;
}

void search(node *first,int x)
{
	node *temp=first;
	int flag=0;
	if(first==NULL)
	{
		printf("there are no elements in the list to search\n");
	}
	else
	{
		while(temp!=NULL)
		{
			if(temp->data==x)
			{
				printf("the element %d is found in the given linked list\n",x);
				flag=1;
				break;
			}
			else
			{
				temp=temp->next;
			}
		}
	}
	if(flag==0)
	{
		printf("the element %d is not found\n",x);
	}
}

node *insert_at_begin(node *first,int x)
{
	node *new=(node *)malloc(sizeof(node));
	//node *temp=first;
	new->data=x;
	new->next=NULL;
	if(first==NULL)
	{
		first=new;
	}
	else
	{
		new->next=first;
		first=new;
	}
	return first;
}

node *insert_at_end(node *first,int x)
{
	node *temp=first;
	node *new=(node *)malloc(sizeof(node));
	new->data=x;
	new->next=NULL;
	if(first==NULL)
	{
		first=new;
	}
	else
	{
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=new;
	}
	return first;
}

node *insert_at_pos(node *first,int pos,int x)
{
	node *temp=first;
	int i;
	node *new=(node *)malloc(sizeof(node));
	new->data=x;
	new->next=NULL;
	int n=count(first);
	if(pos>1 && pos<n)
	{
		for(i=1;i<pos-1;i++)
		{
			temp=temp->next;
		}
		new->next=temp->next;
		temp->next=new;
	}
	return first;
}

node *del_a_ele(node *first,int x)
{
	node *temp=first,*temp1;
	int flag=0;
	if(first->data==x)
	{
		first=first->next;
		free(temp);
	}
	else
	{
		while(temp->next!=NULL)
		{
			if(temp->data==x)
			{
				flag=1;
				break;
			}
			else
			{
				temp1=temp;
				temp=temp->next;
			}
		}
	}
	if(flag==1)
	{
		temp1->next=temp->next;
		free(temp);
	}
	else
	{
		printf("given element not found in the given list to delete\n");
	}
	return first;
}

node *del_at_pos(node *first,int pos)
{
	node *temp=first,*temp1=NULL;
	int i;
	while(i<pos-1)
	{
		temp=temp->next;
		i++;
	}
	temp1=temp->next;
	temp->next=temp1->next;
	free(temp1);
	return first;
}

void sort(node *first)
{
	node *temp1,*temp2;
	int t;
	for(temp1=first;temp1->next!=NULL;temp1=temp1->next)
	{
		for(temp2=temp1->next;temp2!=NULL;temp2=temp2->next)
		{
			if(temp1->data>temp2->data)
			{
				t=temp1->data;
				temp1->data=temp2->data;
				temp2->data=t;
			}
		}
	}
}

node *reverse(node *first)
{
	node *present=first,*prev=NULL,*save;
	while(present!=NULL)
	{
		save=present->next;
		present->next=prev;
		prev=present;
		present=save;
	}
	return prev;
}

/*
void reverse()
{
struct node *prevnode,*currentnode,*nextnode;
prevnode=0;
currentnode=nextnode=head;
while(nextnode!=0)
{
nextnode=nextnode->next;
currentnode->next=prevnode;
prevnode=currentnode;
currentnode=nextnode;
}
*/

int main()
{
	int ch,pos,x,c;
	node *head=NULL;
	while(1)
	{
	printf("1:create\n2:display\n3:count\n4:search\n5:insert_at_beginning\n6:insert_at_end\n7:insert_at_position\n");
	printf("8:delete_a_element\n9:delete_at_position\n10:sort\n11:reverse\n12:exit\n");
	printf("enter ur choice\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:head=create(head);
		case 2:printf("the elements of the linked list are:\n");
		display(head);
		break;
		case 3:c=count(head);
		printf("the no of elements in the linked list are %d\n",c);
		break;
		case 4:printf("enter the value to be searched\n");
		scanf("%d",&x);
		search(head,x);
		break;
		case 5:printf("enter element to be insert at beginning\n");
		scanf("%d",&x);
		head=insert_at_begin(head,x);
		break;
		case 6:printf("enter element to be insert at end\n");
		scanf("%d",&x);
		head=insert_at_end(head,x);
		break;
		case 7:printf("enter position of the element to be inserted in the given linked list\n");
		scanf("%d",&pos);
		printf("enter element of the element to be inserted\n");
		scanf("%d",&x);
		head=insert_at_pos(head,pos,x);
		break;
		case 8:printf("enter element to delete\n");
		scanf("%d",&x);
		head=del_a_ele(head,x);
		break;
		case 9:printf("enter position of the element to delete\n");
		scanf("%d",&pos);
		head=del_at_pos(head,pos);
		break;
		case 10:sort(head);
		break;
		case 11:head=reverse(head);
		break;
		case 12:exit(0);
		break;
		default:printf("enter valid choice\n");
	}
	}
}
