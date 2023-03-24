#include<iostream>
using namespace std;
struct node
{
	int data;
	node *left,*right;
};

node *createnode(int data)
{
	node *temp = new node;
	temp->data= data;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

node *insertbst(node *root,int data)
{
	if(root==NULL)
		return createnode(data);
	if(root->data>data)
		root->left=insertbst(root->left,data);
	else
		{root->right=insertbst(root->right,data);}
	return root;
}

void inorder(node *root)
{
    if(root!=NULL)
    {   
        inorder(root->left);
        cout<<root->data<<"  ";
        inorder(root->right);
    }
}

int h=0,htemp=0;
void height_two(node *root)
{
	if(root==NULL)
	{
		if(htemp>h)
			h=htemp;
			htemp--;
	}	
	else
	{	
		htemp++;
		height_two(root->left);
		height_two(root->right);
	}
}

int height (node *root)
{
	if(root==NULL)
		return 0;
	int hi;
	hi=max(height(root->left),height(root->right))+1;
	return hi;
}

//Copied from stackoverflow
void printBT(const std::string& prefix, node* root, bool isLeft)
{
    if( root != nullptr )
    {
        std::cout << prefix;
        std::cout << (isLeft ? "├──" : "└──" );
        std::cout << root->data << std::endl;
        printBT( prefix + (isLeft ? "│   " : "    "), root->left, true);
        printBT( prefix + (isLeft ? "│   " : "    "), root->right, false);
    }
}

int main()
{
	node *root= new node;
    int t,l;
    cout<<"Enter the root value  ";
    cin>>t;
    root=createnode(t);
    node *i=root;
    cout<<"\nHow many values you want to enter ";
    cin>>l;
    cout<<"\nEnter the values ";
    while(l--)
    {
        cin>>t;
        insertbst(root,t);
    }
    int o=height(root);
    cout<<"\nThe height is "<<o<<endl;
    printBT("", root, false);
    return 0;
}


