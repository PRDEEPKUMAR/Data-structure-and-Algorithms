#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node* left;
    Node* right;
};
Node* newNode(int val)
{

    Node * temp=(Node*)malloc(sizeof(Node));
    temp->data=val;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
void inOrder(Node* root)
{
    if(root==NULL)
        return;
        inOrder(root->left);
        cout<<root->data<<" ";
        inOrder(root->right);

}
void createNode(int P[], Node* A[], int i, Node*&root)
{
    //cout<<"create Node\n";
    if(A[i]!=NULL)
    {
      //  cout<<"one";
        return ;
    }
    A[i]=newNode(i);
   // cout<<P[i]<<"----";
    if(P[i]==-1)
    {
        //cout<<"two\n";
        root=A[i];
        return ;
    }
    if(A[P[i]]==NULL)
    {
        //cout<<"three\n";
        createNode(P,A,P[i],root);

    }
    Node *p=A[P[i]];
    if(p->left==NULL)
    {
       // cout<<"four\n";
        p->left=A[i];
    }
    else{
        //cout<<"five\n";
        p->right=A[i];
    }



}
Node* createTree(int P[],int n)
{
   int i;
   Node * A[n];
   Node *root=NULL;
   for(i=0;i<n;i++)
    A[i]=NULL;
   for(i=0;i<n;i++)
   {
       createNode(P,A,i,root);
       //cout<<"hi";
   }
   return root;
}
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
      int n,i;
      Node* root=NULL;
      cin>>n;
      int P[n];
      for(i=0;i<n;i++)
      {
          cin>>P[i];
      }
      //cout<<"hi\n";
      root=createTree(P,n);
      //cout<<"bye\n";
      inOrder(root);
  }
  return 0;
}
