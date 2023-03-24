#include <iostream>
#include <string.h>

using namespace std;

struct node
{
    int data;
    node *left, *right;
};

node *createnode(int data)
{
    node *temp = new node;
    temp->data = data;
    temp->right = NULL;
    temp->left = NULL;
    return temp;
}

node* insertbst(node *root, int data)
{
    if(root==NULL)
    {
         return createnode(data);
    }
    if(data<root->data)
        root->left=insertbst(root->left , data);
    else if(data>=root->data)
        root->right=insertbst(root->right , data);
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

int height (node *root)
{
    if(root==NULL)
        return 0;
    int hi;
    hi=max(height(root->left),height(root->right))+1;
    return hi;
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
    inorder(root);
    return 0;

}