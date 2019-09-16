/*
Write a C program to implement singly linked list and perform operations like - insert a node,delete a node , display a linked list, reverse a linked list ,sort a list,merging og lists etc
*/


#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node* create(struct node *head)
{
	char ch;
	do
	{
		struct node *ptr,*temp;
		ptr=(struct node*)malloc(sizeof(struct node*));
		printf("\nEnter the data:\n");
		scanf("%d",&ptr->data);
		if(head->next==NULL)
		{
			head->next=ptr;
			ptr->next=NULL;
			temp=ptr;
		}
		else
		{
			temp->next=ptr;
			temp=ptr;
		}
		printf("\nDo you want to add another node?(y/n)\n");
		scanf(" %c",&ch);
	}
	while(ch=='y');
	return head;
}
void display(struct node *head)
{
	struct node *temp;
	if(head->next==NULL)
	{
		printf("\nList empty!!\n");
	}
	else
	{
		temp=head->next;
		printf("\nList elements:\n");
		while(temp!=NULL)
		{
			printf("%d # ",temp->data);
			temp=temp->next;
		}
	}
}
struct node* addbet(struct node *head)
{
	int flag,count;
	struct node *temp,*ptr,*nd;
	ptr=(struct node*)malloc(sizeof(struct node*));
	printf("\nAt which position do you want to add the node?\n");
	scanf("%d",&flag);
	printf("\nEnter Data:\n");
	scanf("%d",&ptr->data);
	temp=head->next;
	count=1;
	if(flag==count)
	{
		head->next=ptr;
		ptr->next=temp;
	}
	while(temp!=NULL)
	{
		if(count==flag-1)
		{
			nd=temp->next;
			temp->next=ptr;
			ptr->next=nd;
			break;
		}
		else
		{
			count++;
			temp=temp->next;
		}
	}
	return head;
}
struct node* delbet(struct node *head)
{
	int flag,count;
	struct node *temp,*nd;
	printf("At which position do you want to delete the node?\n");
	scanf("%d",&flag);
	temp=head->next;
	count=1;
	if(flag==count)
	{
		temp=temp->next;
		head->next=temp;
	}
	while(temp!=NULL)
	{
		if(count==flag-1)
		{
			nd=temp->next;
			nd=nd->next;
			temp->next=nd;
			
			break;
		}
		else
		{
			count++;
			temp=temp->next;
		}
	}
	return head;
}
struct node* reverse(struct node *head)
{
	struct node *p,*q,*r;
	p=NULL;
	q=head->next;
	while(q!=NULL)
	{
		r=q->next;
		q->next=p;
		p=q;
		q=r;
	}
	head->next=p;
	return head;
}
struct node* sort(struct node *head)
{
	int n,i,j;
	struct node *temp,*prev,*curr;
	temp=head->next;
	n=0;
	while(temp!=NULL)
	{
		n++;
		temp=temp->next;
	}
	for(i=0;i<n;i++)
	{
		prev=head;
		curr=prev->next;
		for(j=0;j<n-1;j++)
		{
			temp=curr->next;
			if(curr->data>temp->data)
			{
				prev->next=temp;
				curr->next=temp->next;
				temp->next=curr;
				prev=temp;
			}
			else
			{
				prev=curr;
				curr=curr->next;
			}
		}
	}
	return head;
}
struct node* merge(struct node *head1,struct node *head2,struct node *head3)
{
	struct node *t1,*t2,*t3;
	t1=head1->next;
	t2=head2->next;
	if(t1->data>t2->data)
	{
		head3->next=t2;
		t2=t2->next;
		t3=head3->next;
	}
	else
	{
		head3->next=t1;
		t1=t1->next;
		t3=head3->next;
	}
	while(t1!=NULL && t2!=NULL)
	{
		if(t1->data>t2->data)
		{

			t3->next=t2;
			t2=t2->next;
			t3=t3->next;
		}
		else
		{
			t3->next=t1;
			t1=t1->next;
			t3=t3->next;
		}
	}
	while(t1!=NULL)
	{
		t3->next=t1;
		t1=t1->next;
		t3=t3->next;
	}
	while(t2!=NULL)
	{
		t3->next=t2;
		t2=t2->next;
		t3=t3->next;
	}
	return head3;
}
int main()
{
	int ch;
	struct node *h,*h1,*h2;
	h=(struct node*)malloc(sizeof(struct node*));
	h1=(struct node*)malloc(sizeof(struct node*));	
	h2=(struct node*)malloc(sizeof(struct node*));
	h->next=NULL;
	h1->next=NULL;
	h2->next=NULL;
	h=create(h);
	display(h);
	while(ch!=6)
	{
		printf("\n1:Add node\n2:Delete node\n3:Reverse\n4:Sort\n5:Merge\n6:Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			        h=addbet(h);
				display(h);
				break;
			case 2:
			        h=delbet(h);
				display(h);
				break;
			case 3:
			        h=reverse(h);
				display(h);
				break;	
			case 4:
			        h=sort(h);
				display(h);
				break;
			case 5:
			        h1=create(h1);
				h2=merge(h,h1,h2);
				display(h2);
				break;
			case 6:
			        break;
				
				
		}
	}
	
	
	
	return 0;
}
