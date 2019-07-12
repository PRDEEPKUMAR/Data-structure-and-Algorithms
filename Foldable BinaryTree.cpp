#include<bits/stdc++.h>
using namespace std;
/* You would want to remove below 3 lines if your compiler
supports bool, true and false */

/* A binary tree node has data, pointer to left child
and a pointer to right child */
struct node
{
    int data;
    struct node* left;
    struct node* right;

    node(int x){
        data = x;
        left = right = NULL;
    }
};
/* converts a tree to its mrror image */
void mirror(struct node* node);
/* returns true if structure of two trees a and b is same
Only structure is considered for comparison, not data! */
bool isStructSame(struct node *a, struct node *b);
/* Returns true if the given tree is foldable */
bool isFoldable(struct node *root);
/* UTILITY FUNCTIONS */
/* Change a tree so that the roles of the left and
	right pointers are swapped at every node.
	See http://www.geeksforgeeks.org/?p=662 for details */
void mirror(struct node* node)
{
if (node==NULL)
	return;
else
{
	struct node* temp;
	/* do the subtrees */
	mirror(node->left);
	mirror(node->right);
	/* swap the pointers in this node */
	temp	 = node->left;
	node->left = node->right;
	node->right = temp;
}
}
void insert(struct node *root,int n1,int n2,char lr)
 {
     if(root==NULL)
        return;
     if(root->data==n1)
     {
         switch(lr)
         {
          case 'L': root->left=new node(n2);
                    break;
          case 'R': root->right=new node(n2);
                    break;
         }
     }
     else
     {
         insert(root->left,n1,n2,lr);
         insert(root->right,n1,n2,lr);
     }
 }
/* Driver program to test mirror() */
int main(void)
{
/* The constructed binary tree is
     1
	/ \
   2   3
	\ /
	4 5
*/
int t,k;
    cin>>t;
    while(t--)
    {
    int n;
    cin>>n;
    struct node *root=NULL;
    while(n--)
    {
        char lr;
        int n1,n2;
        cin>>n1>>n2;
        cin>>lr;
        if(root==NULL)
        {
            root=new node(n1);
            switch(lr){
                    case 'L': root->left=new node(n2);
                    break;
                    case 'R': root->right=new node(n2);
                    break;
                    }
        }
        else
        {
            insert(root,n1,n2,lr);
        }
    }
if(isFoldable(root) == 1)
{ cout<<"Yes"<<endl; }
else
{ cout<<"No"<<endl; }
getchar();
    }
return 0;
}


/*This is a function problem.You only need to complete the function given below*/
/* Returns true if the given tree is foldable */
typedef struct node Node;
bool compare(Node* t1,Node* t2)
{
    bool l,r;
    if((!t1->left&&!t1->right)&&(!t2->left&&!t2->right))
    {
        return true;
    }
    else if((t1->left&&!t1->right)&&(!t2->left&&t2->right))
    {
       return compare(t1->left,t2->right);
    }
    else if((!t1->left&&t1->right)&&(t2->left&&!t2->right))
    {
        return compare(t1->right,t2->left);
    }
    else if((t1->left&&t1->right)&&(t2->left&&t2->right))
        {
            l=compare(t1->left,t2->left) ;
            r=compare(t1->right,t2->right) ;
            if(l&&r)
                return true;
            else
                return false;
    }
    else{
        return false;
    }
}
bool isFoldable(struct node *root)
{
    return compare(root->left,root->right);
}
