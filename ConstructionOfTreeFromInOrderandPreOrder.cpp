#include<bits/stdc++.h>
using namespace std;
struct Node
{
  int data;
  Node* left;
  Node* right;
};
Node* newNode(int data)
{
  Node* node = (Node*)malloc(sizeof(Node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return(node);
}
Node *buildTree(int a[],int b[],int str,int end);
int preIndex=0;
void printPostOrder(Node *root){
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		preIndex=0;
		Node *root=NULL;
		int a[n],b[n];
		for(int i=0;i<n;i++)
			cin>>a[i];
		for(int i=0;i<n;i++)
			cin>>b[i];
		root=buildTree(a,b,0,n-1);
		printPostOrder(root);
		cout<<endl;
	}
}

/*This is a function problem.You only need to complete the function given below*/
/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
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
    Node* temp=newNode(postOrder[*pointer]);
    (*pointer)++;
    if(start==end)
        {
            return temp;
        }
    int mid=search(inOrder,start,end,temp->data);
    temp->left=BuildTree(inOrder,postOrder,start,mid-1,pointer);
    temp->right=BuildTree(inOrder,postOrder,mid+1,end,pointer);
    return temp;
}
Node* buildTree(int in[],int pre[], int start, int end)
{

    int pointer=0;
    return BuildTree(in,pre,start,end,&pointer);
}
