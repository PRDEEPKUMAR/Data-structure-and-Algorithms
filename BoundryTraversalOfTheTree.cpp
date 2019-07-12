
#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* newNode(int data)
{
    struct Node* Node = (struct Node*)
                        malloc(sizeof(struct Node));
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;
    return(Node);
}
void printBoundary(Node *root);
int height(struct Node *root)
{
    if(root==NULL)
        return 0;
    int l = 1+height(root->left);
    int r=1+height(root->right);
    if(l>r)
        return l;
    else
        return r;
}
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
      //  cout << n1 << " " << n2 << " " << (char)lr << endl;
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
    printBoundary(root);
   cout<<endl;
  }
    return 0;
}

void printLeftBoundry(Node * P)
{
    if(P==NULL)
        return;
        if(P->left)
        {
            cout<<P->data<<" ";
            printLeftBoundry(P->left);
        }
        else if(P->right)
        {
            cout<<P->data<<" ";
            printLeftBoundry(P->right);
        }

}
void printRightBoundry(Node * P)
{
    if(!P)
    return ;
        if(P->right)
        {

            printRightBoundry(P->right);
            cout<<P->data<<" ";
        }
        else if(P->left)
        {
            printRightBoundry(P->left);
            cout<<P->data<<" ";
        }


}
void print_all_leaf_nodes(Node * root)
{
    if(root==NULL)
        return ;
    else if(!root->left&&!root->right)
        cout<<root->data<<" ";
    print_all_leaf_nodes(root->left);
    print_all_leaf_nodes(root->right);

}
void BoundryTraversal(Node * root)
{
   // cout<<"\nLeft Boundry "<<endl;
   cout<<root->data<<" ";
    printLeftBoundry(root->left);
     // cout<<"\nLeaf node "<<endl;
    print_all_leaf_nodes(root);

   // cout<<"\nRight boundry "<<endl;
    printRightBoundry(root->right);

    return ;
}
void printBoundary(Node *root)
{
    BoundryTraversal(root);

}
