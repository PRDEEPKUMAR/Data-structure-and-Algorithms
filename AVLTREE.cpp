#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
int height(struct node*);
typedef struct node
{
    int val;
    struct node* left;
    struct node* right;
    int ht;
} node;
struct node* newNode(int val)
{
 struct node* temp=(struct node*)malloc(sizeof(struct node));
 temp->left=NULL;
 temp->right=NULL;
 temp->ht=1;
 temp->val=val;
 return temp;

}
int getBalance(struct node* r)
{
    if(r==NULL)
        return 0;
    else
        return height(r->left)-height(r->right);
}
int max(int a,int b)
{

    return a>b?a:b;
}
int height(struct node* r)
{
if(r==NULL)
    return 0;
else
    return r->ht;
}
struct node* rotateLeft(struct node* x)
{
    //printf("Rotate left");
    struct node *y,*t2;
    y=x->right;
    t2=y->left;
    y->left=x;
    x->right=t2;
    x->ht=max(height(x->left),height(x->right))+1;
    y->ht=max(height(y->left),height(y->right))+1;
    return y;
}
struct node* rotateRight(struct node *y)
{
    //printf("Rotate right\n");
    struct node *x,*t2;
    x=y->left;
    t2=x->right;
    x->right=y;
    y->left=t2;
    x->ht=max(height(x->left),height(x->right))+1;
    y->ht=max(height(y->left),height(y->right))+1;
    return x;
}
node* insert(struct node *n,int val)
{
    int balance;
    if(n==NULL)
        return newNode(val);
    else if(val>n->val)
    {
        n->right=insert(n->right,val);
    }
    else if(val<n->val)
    {
        n->left=insert(n->left,val);
    }
    else
    {
        return n;
    }
    n->ht=max(height(n->left),height(n->right))+1;
  balance=getBalance(n);
    if(balance>1&&val<n->left->val)
        return rotateRight(n);

    if(balance>1&&val>n->left->val)
    {
        n->left=rotateLeft(n->left);
        return rotateRight(n);
    }
    if(balance<-1&&val>n->right->val)
    {
        return rotateLeft(n);
    }
    if(balance<-1&&val<n->right->val)
    {
        n->right=rotateRight(n->right);
        return rotateLeft(n);
    }
    return n;
}
void preOrder(struct node* n)
{
    if(n==NULL)
        return ;
    else
    {
        printf(" %d ",n->val,n->ht);
        preOrder(n->left);
        preOrder(n->right);
    }
}
/*struct node* delete(struct Node*)
{

}*/
int heit(struct node* r )
{
    int l=0,g=0;
    if(!r->left&&!r->right)
    {
        return 0;

    }
    else if(r->left&&!r->right)
    {
        return 1+heit(r->left);
    }
    else if(!r->left&&r->right)
    {
        return 1+heit(r->right);
    }
    else
    {
        l=1+heit(r->left);
        g=1+heit(r->right);
        if(l>g)
            return l;
        else
            return g;
    }
}
int countnode(struct node *r)
{

    int left=0,right=0;
    if(!r->left&&!r->right)
    {
        return 1;
    }
    else if(r->left&&!r->right)
    {
        return 1+countnode(r->left);
    }
    else if(!r->left&&r->right)
    {
        return 1+countnode(r->right);
    }
    else
    {
        left=1+countnode(r->left);
        right=1+countnode(r->right);
        return right+left;
    }
}
int main()
{
    struct node* root=NULL;
    root=insert(root,3);
    root=insert(root,2);
    root=insert(root,4);
    //root=insert(root,5);
   // root=insert(root,6);

    preOrder(root);
    cout<<"Heigh of the Tree : "<<height(root)<<endl;
    cout<<"Node of the Tree  : "<<countnode(root);

    return 0;
}
