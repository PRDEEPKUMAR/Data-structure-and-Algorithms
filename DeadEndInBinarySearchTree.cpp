#include<bits/stdc++.h>
using namespace std;
struct Node {
int data;
struct Node * right, * left;
};
void insert(Node ** tree, int val)
{
    Node *temp = NULL;
    if(!(*tree))
    {
        temp = (Node *)malloc(sizeof(Node));
        temp->left = temp->right = NULL;
        temp->data = val;
        *tree = temp;
        return;
    }
    if(val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }
}
int getCountOfNode(Node *root, int l, int h)
{
    if (!root) return 0;
    if (root->data == h && root->data == l)
        return 1;
    if (root->data <= h && root->data >= l)
         return 1 + getCountOfNode(root->left, l, h) +
                    getCountOfNode(root->right, l, h);
    else if (root->data < l)
         return getCountOfNode(root->right, l, h);
    else return getCountOfNode(root->left, l, h);
}
bool isDeadEnd(Node *root);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Node *root;
        Node *tmp;
    //int i;
        root = NULL;
        int N;
        cin>>N;
        for(int i=0;i<N;i++)
        {
            int k;
            cin>>k;
            insert(&root, k);
        }

     cout<<isDeadEnd(root);
     cout<<endl;
    }
}

bool isDeadEnd(Node *t)
{
    bool l,r;
    if(t==NULL)
        return false;
    if(t->left)
    {
        if(!t->left->left&&!t->left->right)
        {
            if(abs(t->left->data-t->data)==1)
            {
                return true;
            }
            else
                return false;
        }
    }
    if(t->right)
    {
        if(!t->right->left&&!t->right->right)
        {
            if(abs(t->right->data-t->data)==1)
                return true;
            else
                return false;

        }
    }
    l=isDeadEnd(t->left);
    r=isDeadEnd(t->right);
    if(l||r)
        return true;
    else
      return false ;
}
