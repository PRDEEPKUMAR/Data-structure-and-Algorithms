#include<bits/stdc++.h>
using namespace std;
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node)
{
  if (node == NULL)
     return;
   /* then print the data of node */
  printf("%d ", node->data);
  /* first recur on left child */
  preOrder(node->left);
  /* now recur on right child */
  preOrder(node->right);
}
Node *buildTree(int in[], int post[], int n);
int main()
{
	int t,n;
	cin>>t;
	int in[1000], post[1000];
	while(t--)
	{
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>in[i];
		for(int i=0;i<n;i++)
			cin>>post[i];
        Node *root = buildTree(in, post, n);
        preOrder(root);
		cout<<endl;
	}
	return 0;
}


/*This is a function problem.You only need to complete the function given below*/
/* Tree node structure
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/
// Function should construct tree and return
// root of it.  in[] stores inorder traversal
// post[] stores postorder traversal.  n is
// size of these arrays
int search(int A[], int start, int end ,int val )
{

    for(int i=start;i<=end;i++)
    {

        if(A[i]==val)
        {
            return i;
        }
    }
}
Node* BuildTree(int inOrder[],int postOrder[],int start, int end,int *pointer)
{
    if(start>end)
    {
        return NULL;
    }
    Node* temp=new Node(postOrder[*pointer]);
    (*pointer)++;
    if(start==end)
        {
            return temp;
        }
    int mid=search(inOrder,start,end,temp->data);
    temp->right=BuildTree(inOrder,postOrder,mid+1,end,pointer);
    temp->left=BuildTree(inOrder,postOrder,start,mid-1,pointer);
    return temp;
}
Node *buildTree(int in[], int post[], int n)
{
    int pointer=0;
    reverse(post,post+n);
    return BuildTree(in,post,0,n-1,&pointer);
}
