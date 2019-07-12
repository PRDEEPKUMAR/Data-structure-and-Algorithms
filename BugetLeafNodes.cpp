#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
struct node* newnode(int data)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}
int getCount(struct node* node, int k);
int main()
{
  int t;
  struct node *child;
  scanf("%d", &t);
  while (t--)
  {
     map<int, node*> m;
     int n;
     scanf("%d",&n);
     struct node *root = NULL;
     if(n==1)
     {
        int a;
        cin>>a;
        cout<<a<<endl;
     }else{
     while (n--)
     {
        node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
      //  cout << n1 << " " << n2 << " " << (char)lr << endl;
        if (m.find(n1) == m.end())
        {
           parent = newnode(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];
        child = newnode(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
     int tmp;
     cin>>tmp;
     cout<<getCount(root, tmp)<<endl;
  }
  }
  return 0;
}


/*This is a function problem.You only need to complete the function given below*/
/*
Structure of the node of the binary tree is as
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
*/
// your are required to complete this function
// function should return the number of leaf node
// one can visit
typedef struct node Node;
void buget(Node* t,int i,vector<int> &v)
{
    if(t==NULL)
    return ;
    if(!t->left&&!t->right)
    {
          v.insert(v.end(),i);
    }
    buget(t->left,i+1,v);
    buget(t->right,i+1,v);

}
int getCount(struct node* node, int k)
{
    int count=0;
    int cost=k;
    Node* temp=NULL;
    int level=1;
  queue<Node*> q;
  q.push(node);
  q.push(NULL);
  while(!q.empty())
  {
      temp=q.front();
      q.pop();
      if(temp==NULL&&q.front()==NULL)
       {
        return count;
       }
      else if(temp==NULL)
      {
          level++;
          q.push(NULL);
      }
      else
      {
          if(!temp->left&&!temp->right)
          {
              if(level<=cost)
              {

                  cost=cost-level;
                  count++;
              }
          }
          if(temp->left)
            q.push(temp->left);
          if(temp->right)
          q.push(temp->right);
      }
  }
}

