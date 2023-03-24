#include<iostream>

using namespace std;
struct node {
      int data;
      node *next;
      //node(int x) : val(x), next(NULL) {}
     };

node *createnode(int data)
{
	node *temp=new node;
    temp->data=data;
    temp->next=NULL;
    return temp;
}

void insertlast(node *head, int data)
{
	node *temp = createnode(data);
	node *i=head;
	for(;i->next!=NULL;i=i->next);
	i->next= temp;	
}

void showlist(node* head)
{	node* t=head;
	cout<<"\nIn the showlist function\n";
	for(;t!=NULL;t=t->next)
	{
		cout<<t->data<<" -> ";
	}
}

int main ()
{	
	 /*char *s = "Hey there Abhijeet!";
     string str(s);
     cout<<str;*/
	node *head=new node;
	head->next=NULL;

	cout<<"Enter the length of the list ";
	int l;
	cin>>l;
	int l1=l;
	int data;

	while(l1--)
	{	cout<<"\nEnter the data "<<l-l1<<"  ";
		cin>>data;
		if(!(l-l1-1))
			head=createnode(data);
		
		else
			insertlast(head,data);	

	}
	showlist(head);

	return 0;
}