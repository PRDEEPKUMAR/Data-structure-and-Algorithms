#include <bits/stdc++.h>
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
int height(Node * t);
bool isBalanced(struct Node *root);
/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
/* Driver program to test size function*/
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
           parent = new Node(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];
        child = new Node(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
     cout << isBalanced(root) << endl;
     cout<<height(root->left->right)-height(root->left->left);
  }
  return 0;
}

int height(Node * t)
{
    int left,right;
    if(t==NULL)
        return 0;
    else if(!t->left&&!t->right)
        return 1;
    else if(t->left&&!t->right)
    {
        return height(t->left)+1;
    }
    else if(!t->left&&t->right)
    {
        return height(t->right)+1;
    }
    else if(t->left&&t->right)
    {
        left=height(t->left)+1;
        right=height(t->right)+1;
        if(left<right)
            return right;
        else
            return left;
    }
}

// This function should return tree if passed  tree
// is balanced, else false.
bool isBalanced(Node *t)
{
    int l,r;
    bool left,right;

     if(!t->left&&!t->right)
    {
        return true;
    }
    else if(t->left&&!t->right)
        {
            if(abs(height(t->left)-height(t->right))>1)
            {
                return false;
            }
            else
            {
                isBalanced(t->left);
            }
        }
    else if(!t->left&&t->right)
        {
            if(abs(height(t->left)-height(t->right))>1)
            {
                return false;
            }
            else
            {
                isBalanced(t->right);
            }
        }
    else if(t->left&&t->right)
    {
        l=height(t->left);
        r=height(t->right);
        if(abs(l-r)>1)
            return false;
        left=isBalanced(t->left);
        right=isBalanced(t->right);
        if(left&&right)
        {
            return true;

        }
        else return false;

    }


}
