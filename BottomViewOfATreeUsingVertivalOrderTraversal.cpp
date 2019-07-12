#include<bits/stdc++.h>
using namespace std;
// Tree node class
struct Node
{
    int data; //data of the node
    Node *left, *right; //left and right references
    // Constructor of tree node
    Node(int key)
    {
        data = key;
        left = right = NULL;
    }
};
// Method that prints the bottom view.
void bottomView(Node *root);
/* Driver program to test size function*/
int main()
{
  int t;
  struct Node *child;
  scanf("%d", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
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
     bottomView(root);
     cout << endl;
  }
  return 0;
}


/*This is a function problem.You only need to complete the function given below*/
/* Tree node class
struct Node
{
    int data; //data of the node
    Node *left, *right; //left and right references
    // Constructor of tree node
    Node(int key)
    {
        data = key;
        left = right = NULL;
    }
}; */
// Method that prints the bottom view.
void vot(Node * t, int key,multimap<int , int> &m1,int &minlvl, int &maxlvl)
{
   if(t==NULL)
    return ;
    if(minlvl>key)
        minlvl=key;
    if(maxlvl<key)
        maxlvl=key;
        m1.insert(pair<int , int>(key,t->data));
    vot(t->left,key-1,m1,minlvl,maxlvl);
    vot(t->right,key+1,m1,minlvl,maxlvl);
}
void verticalOrder(Node* t)
{
    int u=0,l=9999999;
    multimap<int,int> m1;
    vot(t,0,m1,l,u);
    l=abs(l);

    int A[1000]={0};
    for(auto it=m1.begin();it!=m1.end();it++)
    {

        //cout<<it->first<<" ";
        //cout<<it->second<<" \n";
         A[l+it->first]=it->second;
    }

    for(int i=0;i<=u+l;i++)
        cout<<A[i]<<" ";

}

void bottomView(Node *root)
{
    verticalOrder(root);
}

