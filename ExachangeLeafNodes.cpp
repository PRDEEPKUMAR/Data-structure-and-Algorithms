#include <bits/stdc++.h>
using namespace std;
struct Node
{
	int data;
	struct Node *left, *right;
};
Node* newNode(int data)
{
	Node *temp = new Node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}
void printInorder(Node* node)
{
	if (node == NULL)return;
	printInorder(node->left);
	cout<<node->data<<" ";
	printInorder(node->right);
}
void pairwiseSwap(Node *root);
int main()
{
  int t;
  scanf("%d", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     struct Node *child;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
        if (m.find(n1) == m.end())
        {
           parent = newNode(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];
        child = newNode(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
     pairwiseSwap(root);
     printInorder(root);
     cout<<" ";
  }
  return 0;
}

/*This is a function problem.You only need to complete the function given below*/
//User function Template for C++
/*
struct Node
{
	int data;
	struct Node *left, *right;
};
*/
// your task is to complete this function
void store(Node* t , vector<Node*> &v)
{

    if(t==NULL)
        return ;
    else if(!t->left&&!t->right)
    {

        v.insert(v.end(),t);
    }
    store(t->left,v);
    store(t->right,v);
}
void pairwiseSwap(Node *root)
{
    vector<Node*> v;
    int m,i,temp;
    store(root,v);
    if(v.size()%2!=0)
        m=v.size()-1;
    else
        m=v.size();
        for(int i=0;i<m;i=i+2)
        {
            temp=v[i]->data;
            v[i]->data=v[i+1]->data;
            v[i+1]->data=temp;
        }
}
