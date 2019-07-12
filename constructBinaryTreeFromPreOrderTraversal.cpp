#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
};
struct Node* newNode (int data)
{
	Node* temp = new Node;
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}
void printInorder (struct Node* node)
{
	if (node == NULL)return;
	printInorder(node->left);
	printf("%d ", node->data);
	printInorder (node->right);
}
Node* constructTree(int n, int pre[], char preLN[]);
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        Node* root = NULL;
        int n;
        cin>>n;
        int pre[n];
        char preLN[n];
        for(int i=0; i<n; i++)cin>>pre[i];
        for(int i=0; i<n; i++)cin>>preLN[i];
        root = constructTree (n, pre, preLN);
        printInorder(root);
        cout<<endl;
    }
	return 0;
}

// function should return the root of the new binary tree formed
struct Node *constructTree(int n, int pre[], char preLN[])
{
    int i=0;
    stack<Node *> s;
    Node* root=NULL,*temp,*r;
    while(i<n)
    {
        if(preLN[i]=='N')
        {
            if(root==NULL)
            {
                root=newNode(pre[i]);
                s.push(root);

            }
            else
            {
                if(!s.top()->left&&!s.top()->right)
                {
                     r=s.top();
                     r->left=newNode(pre[i]);
                     s.push(r);
                }
                r=s.top()
                while(r->left!=NULL)
                {
                    r=r->left;
                }
                r->left=newNode(pre[i]);
                r=r->left;
                s.push(r);
            }
            i++;

        }
        else if(preLN[i]=='L')
        {

            if(!s.empty())
            {
                if(!s.top()->left&&!s.top()->right)
                {
                    s.top()->left=newNode(pre[i]);



                }
                 else if(s.top()->left&&!s.top()->right)
                {
                    s.top()->right=newNode(pre[i]);
                    s.pop();

                }
                else if(s.top()->left&&s.top()->right)
                {
                    s.pop();
                }
            }
            i++;

        }
    }
    return root;
}
