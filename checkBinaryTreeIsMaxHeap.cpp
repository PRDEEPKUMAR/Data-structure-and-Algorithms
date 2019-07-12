#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data)
{
  struct Node* node = new Node;
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return(node);
}
bool isHeap(struct Node * tree);
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
     cout << isHeap(root)<< endl;
  }
  return 0;
}


bool isHeap(Node * t)
{
    bool l,r;
    if(!t->left&&!t->right)
    {
        return true;
    }
    else if(t->left&&!t->right)
    {
        if(t->left->data<t->data)
            isHeap(t->left);
        else
            return false;
    }
    else if(!t->left&&t->right)
    {

        if(t->right->data<t->data)
        {
            isHeap(t->right);
        }
        else
            return false;

    }
    else if(t->left&&t->right)
    {
        if(t->left->data<t->data&&t->right->data<t->data)
        {
            l=isHeap(t->left);
            r=isHeap(t->right);
            if(l&&r)
                return true;
            else
                return false;
        }
        else
              return false;
    }
}
