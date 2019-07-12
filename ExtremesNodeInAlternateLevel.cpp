#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

Node* newNode(int data)
{
    Node* node = new Node;
    node->data = data;
    node->right = node->left = NULL;
    return node;
}
/* Function to print nodes of extreme corners
of each level in alternate order */
void printExtremeNodes(Node* root);
/* Driver program to test above functions*/
int main()
{
   int t;
  scanf("%d", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     Node *root = NULL;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
       cout << n1 << " " << n2 << " " << (char)lr << endl;
        if (m.find(n1) == m.end())
        {
           parent = newNode(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];
        Node *child = newNode(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
   printExtremeNodes(root);
   cout<<endl;
  }
    return 0;
}


/* Function to print nodes of extreme corners
of each level in alternate order */
void printSpiral(Node *root)
{
    Node* temp;
    stack<Node*> s1,s2;
    s1.push(root);
    int i=0;
    while(!s1.empty()||!s2.empty())
    {
        if(!s1.empty())
        {
            if(!s2.empty())
            {
                cout<<s2.top()->data<<" ";
            }
            while(!s1.empty())
        {
            temp=s1.top();
            s1.pop();
          //  cout<<temp->data<<" ";
            if(temp->left)
            {
             //   cout<<temp->data<<" ";
                s2.push(temp->left);
            }
            if(temp->right)
            {
          // cout<<temp->data<<" ";
                s2.push(temp->right);
            }

        }
        }
        else if(!s2.empty())
        {
            while(!s2.empty())
        {

             if(!s1.empty())
            {
                cout<<s1.top()->data<<" ";
            }
            temp=s2.top();
            s2.pop();
           // cout<<temp->data<<" ";
            if(temp->right)
            {
             //   cout<<temp->data<<"  ";
                s1.push(temp->right);
            }
            if(temp->left)
               {

                   s1.push(temp->left);
               }
        }
        }

    }
}
void printExtremeNodes(Node* root)
{
     Node* temp;
    stack<Node*> s1,s2;
    s1.push(root);
    int i=0;
    while(!s1.empty()||!s2.empty())
    {
        if(!s1.empty())
        {
            if(!s2.empty())
            {
                cout<<s2.top()->data<<" ";
            }
            while(!s1.empty())
        {
            temp=s1.top();
            s1.pop();
            if(temp->left)
            {
                s2.push(temp->left);
            }
            if(temp->right)
            {
                s2.push(temp->right);
            }

        }
        }
        else if(!s2.empty())
        {
             if(!s1.empty())
            {
                cout<<s1.top()->data<<" ";
            }
            while(!s2.empty())
        {
            temp=s2.top();
            s2.pop();

            if(temp->right)
            {
                s1.push(temp->right);
            }
            if(temp->left)
               {

                   s1.push(temp->left);
               }
        }
        }

    }
}

