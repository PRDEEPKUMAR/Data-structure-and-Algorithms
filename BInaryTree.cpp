#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<iostream>
#include<bits/stdc++.h>
int main();
using namespace std;
struct Node;
int search(Node*,int );
struct Node
{
    int data;
    struct Node *right;
    struct Node *left;
    struct Node *nextRight;
};
struct Node *root=NULL;
int binary_search_tree(struct Node* t)
{
    int l=0,r=0;
    if(t==NULL)
    {
       // cout<<"one"<<endl;
        return 0;
    }
    else if(!t->left&&!t->right)
    {

        return 0;
    }
    else if(t->left&&!t->right)
    {
        if(t->data>t->left->data)
        {
         //   cout<<"two i"<<endl;
            return binary_search_tree(t->left);

        }
        else
        {
           // cout<<"two ii"<<endl;
            return 1;

        }
    }
    else if(!t->left&&t->right->data)
    {
        if(t->data<t->right->data)
        {
             //cout<<"three i"<<endl;
            return binary_search_tree(t->right);
        }
        else{
               //  cout<<"three ii"<<endl;
            return 1;
        }
    }
    else if(t->left&&t->right)
    {
        if(t->data>t->left->data&&t->data<t->right->data)
           {
                //cout<<"four i"<<endl;
        l=binary_search_tree(t->left);
        r=binary_search_tree(t->right);
         if(l==1)
            return l;
         else
            return r;
         }
        else
        {
          //  cout<<"four  ii"<<endl;
            return 1;
        }

    }

}
struct Node* insertBST(struct Node *r,int val)
{
    if(r==NULL)
    {
      r=(struct Node*)malloc(sizeof(struct Node));
        r->left=r->right=NULL;
        r->data=val;
        return r;

    }
    else if(r->data>val)
    {
    r->left=insertBST(r->left,val);
    }
    else if(r->data<val)
       r->right=insertBST(r->right,val);
       return root;
}
void inOrderNonRecursive(struct Node *ptr)
{
    int top=-1;
    struct Node  *stack[100];
    while(top!=-1||ptr!=NULL)
    {
        if(ptr!=NULL)
        {
            stack[++top]=ptr;
            ptr=ptr->left;
        }
        else
            {
                ptr=stack[top--];
                printf(" %d ",ptr->data);
                ptr=ptr->right;

        }
    }

}
void preOrder(struct Node *r)
{

    if(r==NULL)
        return ;
    printf(" %d  ",r->data);
    preOrder(r->left);
    preOrder(r->right);
}
void create()
{
    int  n;
    char ch='N';
    if(root==NULL)
    {
        printf("Enter the value :-");
        scanf("%d",&n);
        root=insertBST(root,n);
         printf("Press Y to to continue....");
        ch=getch();

    }
        while(ch=='y'||ch=='Y')
    {
         printf("\nEnter the value :-");
        scanf("%d",&n);
        insertBST(root,n);
        printf("Press Y to to continue....");
        ch=getch();

    }

}
void postOrderNonRecursive(struct Node *ptr)
{
    int top=-1;

    struct Node *stack[100];
     xyz:
    while(top!=-1||ptr!=NULL)
    {
       stack[++top]=ptr;
       if(ptr->right!=NULL)
        {
            ptr=ptr->right;
            ptr=ptr;
        }
       ptr=ptr->left;
    }
    ptr=stack[top--];
    if(ptr!=NULL&&top!=-1)
    {

        while(ptr>0)
        {
            printf("%d",ptr->data);
            ptr=stack[top--];
        }
    }
    if(ptr<0)
    {
        ptr=ptr;
        goto xyz;
    }



}

void createWithArray(int A[],int n)
{
    int i;
    if(root==NULL)
        root=insertBST(root,A[0]);
    for(i=1;i<n;i++)
    {
        insertBST(root,A[i]);
    }


}
void nonRecursivePreOrder(struct Node *ptr)
{
    int top=-1;
     struct Node *stack[100];
    top++;
    stack[top]=ptr;
    while(top!=-1)
    {
        ptr=stack[top--];
        if(ptr!=NULL)
        {
            printf(" %d ",ptr->data);
            stack[++top]=ptr->right;
            stack[++top]=ptr->left;
        }
    }
}
void inorder(struct Node *r)
{
    if(r!=NULL)
    {
        inorder(r->left);
        printf(" %d ",r->data);
        inorder(r->right);
    }


}
void postorder(struct Node *r)
{
    if(r!=NULL)
    {
        inorder(r->left);

        inorder(r->right);
        printf(" %d ",r->data);
    }


}
struct Node* findMax(struct Node* r)
{
    if(r==NULL)
    {
        return r;
    }
    else{
        while(r->right!=NULL)
        {
            r=r->right;
        }
        return r;
    }


}

struct Node* delete_Node(struct Node *r,int val)
{
    if(r==NULL)
    {
        printf("Tree Empty");
        return  r;
    }
    if(val>r->data)
    {
        r->right=delete_Node(r->right,val);
        return r;
    }
    else if(val<r->data)
    {
        r->left=delete_Node(r->left,val);
        return r;
    }
    else if(val==r->data)
    {
        if(r->right!=NULL&&r->left!=NULL)
        {
            struct Node *temp=findMax(r->left);
            r->data=temp->data;
            r->left=delete_Node(r->left,r->data);
            return r;


        }
        else if(r->right==NULL&&r->left==NULL)
        {
            free(r);
            return NULL;

        }
        else if(r->left==NULL)
        {
            struct Node *temp=r->right;
            free(r);
            return temp;
        }
        else
        {

            struct Node* temp=r->left;
            free(r);
            return temp;
        }


    }

}

void  level(struct Node* r)
{
    struct Node *ptr=r;
    struct Node *Queue[100];
    int front=-1,rear=-1;
        front=rear=0;
        Queue[front]=root;
    while(front!=rear+1)
        {
            ptr=Queue[front++];
            printf("%d ",ptr->data);
            if(ptr->left!=NULL)
            {
                Queue[++rear]=ptr->left;
            }
           if(ptr->right!=NULL)
            {
               Queue[++rear]=ptr->right;
            }

        }

}

void  linebyline(struct Node* r)
{
    struct Node *ptr=r;
    struct Node *Queue[100];
    int front=-1,rear=-1;
        front=rear=0;
        Queue[front]=root;
        rear++;
        Queue[rear]=NULL;
    while(front!=rear+1)
        {
            ptr=Queue[front++];
            if(ptr==NULL)
                {
                    if(front!=rear+1)
                    {
                      printf("$ ");
                      rear++;
                      Queue[rear]=NULL;
                    }
                }
            else
           {

            printf("%d ",ptr->data);
            if(ptr->left!=NULL)
            {
                Queue[++rear]=ptr->left;
            }
           if(ptr->right!=NULL)
            {
               Queue[++rear]=ptr->right;
            }
           }

        }
        cout<<"$";

}
int max_node(struct Node *t)
{
    int lmax=0,rmax=0;
    if(t==NULL)
        return 0;
    else if(!t->left&&!t->right)
    {
        return t->data;
    }
    else if(!t->left&&t->right)
    {
        return max_node(t->right);
    }
    else if(t->left&&!t->right)
    {
        return max_node(t->left);
    }
    else
    {
        lmax=max_node(t->left);
        rmax=max_node(t->right);
        if(lmax>rmax)
            return lmax;
        else
            return rmax;
    }
}
 int min_node(struct Node *t)
 {


 }
 int sum_node(struct Node *t)
 {
    int lsum=0,rsum=0;
     if(t==NULL)
        return 0;
     else if(!t->left&&!t->right)
     {

        return t->data;
     }
     else if(t->left&&!t->right)
     {

        return lsum=t->data+sum_node(t->left);
     }
     else if(!t->left&&t->right)
     {
        return rsum=t->data+sum_node(t->right);
     }
     else
     {
         lsum=sum_node(t->left);
         rsum=sum_node(t->right);
         return lsum+rsum+t->data;
     }

 }
 int ls(struct Node *t)
 {
     static int sum=0;
     if(t==NULL)
        return 0;
     else if(!t->left&&!t->right)
     {
         return sum=sum+t->data;
     }
     else
     {
         ls(t->left);
         ls(t->right);
     }


 }
 int  LCA(Node *t , int val1,int val2)     ///Not Perfect Code
 {
     static int ans=1;
     int left,right;
     if(t==NULL)
        return 0;
     left=search(t->left,val1);
     right=search(t->right,val2);
     cout<<"\nleft "<<left<<" right "<<right<<endl;
      if(left&&right)
      {
          cout<<"left&&right";
          return t->data;
      }
      else if(left&&!right)
      {
          cout<<"left";
          return LCA(t->left,val1,val2);
      }
      else if(!left&&right)
      {
          cout<<"right";
          return LCA(t->right,val1,val2);
      }
      else if(!left &&!right)
      {
          cout<<" Nahai hai  ";
          return -1;
      }



 }
 int search(Node* t,int val)   ///Function to search a value ion binary search tree.
 {
     if(t==NULL)
     {
            return 0;
     }
     else if(t->data==val)
     {
         return 1;
     }
     search(t->left,val);
     search(t->right,val);
}
bool checkBST(Node* t) {
    bool l,r,tr;
    if(t==NULL)
    {
        tr=true;
        return t;
    }
    else if(!t->left&&!t->right)
    {
        tr=true;
        return true;
    }
    else if(t->left&&!t->right)
    {
        if(t->data>t->left->data)
        {

        tr=checkBST(t->left);
            return tr;

        }
        else
        {
            tr=false;
            return false;
        }
    }
    else if(!t->left&&t->right->data)
    {
        if(t->data<t->right->data)
        {
            tr=checkBST(t->right);
            return tr;
        }
        else{
                tr=false;
            return false;
        }
    }
    else if(t->left&&t->right)
    {
        if(t->data>t->left->data&&t->data<t->right->data)
        {
        l= checkBST(t->left);
        r= checkBST(t->right);
         if(l==false||r==false)
         {
             tr=false;
            return tr;
         }
         else
         {
             tr=true;
            return tr;
         }
         }
        else
        {
            tr=false;
            return tr;
        }
    }
    return tr;
}

int  print_left_leaf(struct Node *t)
{
   int sum;
    if(t==NULL)
        return 0;
    if(t->left)
    {
        if(t->left->left==NULL)
        {
            sum=sum+t->left->data;
        }
    }
     sum=print_left_leaf(t->left);
     sum=print_left_leaf(t->right);
    return sum;
}
int  print_right_leaf(struct Node *t)
{
     int sum=0;
    if(t==NULL)
        return 0;
    if(t->right)
    {
        if(t->left->left==NULL)
        {
            sum=sum+t->right->data;
        }
    }
    sum=print_left_leaf(t->left);
    sum=print_left_leaf(t->right);
    return sum;
}
int  isFullTree (struct Node* t)
{
    bool l,r;
     if(!t->left&&!t->right)
        return 1;
    else if(!t->left&&t->right)
    {
        return 0;
    }
    else if(t->left&&!t->right)
    {
        return 0;
    }
    else if(t->left&&t->right)
    {
        l=isFullTree(t->left);
        r=isFullTree(t->right);
        if(l==1&&r==1)
        return 1;
        else
        return 0;
    }
}
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
            while(!s1.empty())
        {
            temp=s1.top();
            s1.pop();
            cout<<temp->data<<" ";
            if(temp->right)
            {
             //   cout<<temp->data<<" ";
                s2.push(temp->right);
            }
            if(temp->left)
            {
          // cout<<temp->data<<" ";
                s2.push(temp->left);
            }

        }
        }
        else if(!s2.empty())
        {
            while(!s2.empty())
        {

            temp=s2.top();
            s2.pop();
            cout<<temp->data<<" ";
            if(temp->left)
            {
             //   cout<<temp->data<<"  ";
                s1.push(temp->left);
            }
            if(temp->right)
               {
               //  cout<<temp->data<<" ";
                   s1.push(temp->right);
               }
        }
        }

    }
}
void ReverseLevelOrderTraversal(Node * root)
{
    Node * temp=root;
    queue<Node*> q1;
    stack<Node*> s1;
    q1.push(root);
    while(!q1.empty())
    {
        temp=q1.front();
        q1.pop();
            if(temp->right)
            {
                q1.push(temp->right);
            }
            if(temp->left)
            {
                q1.push(temp->left);
            }
            s1.push(temp);
    }
        while(!s1.empty())
        {
            temp=s1.top();
            cout<<temp->data<<" ";
            s1.pop();
        }
}
void Pblvl(Node * root)
{
    Node* temp1,*temp2;
    queue<Node*> q1;
    cout<<root->data<<" ";
    if(root->left)
    q1.push(root->left);
    if(root->right)
        q1.push(root->right);
    while(!q1.empty())
    {
        temp1=q1.front();
        q1.pop();
        temp2=q1.front();
        q1.pop();
        cout<<temp1->data<<" "<<temp2->data<<" ";
        if(temp1->left)
        {
            q1.push(temp1->left);
        }
        if(temp2->right)
        {
            q1.push(temp2->right);
        }
        if(temp1->right)
        {
            q1.push(temp1->right);
        }
        if(temp2->left)
        {
            q1.push(temp2->left);
        }

    }
}
void plsv_set_2(Node* root)
{
    Node* temp1, *temp2;
    queue<Node*> q1;
    stack<Node*> s1;
    q1.push(root->right);
    q1.push(root->left);
    s1.push(root);
    while(!q1.empty())
    {

        temp1=q1.front();
        q1.pop();
        temp2=q1.front();
        q1.pop();
        if(temp2->left)
            q1.push(temp2->left);
        if(temp1->right)
        {
            q1.push(temp1->right);
        }
        if(temp2->right)
        {
            q1.push(temp2->right);
        }
        if(temp1->left)
        {
            q1.push(temp1->left);
        }
        s1.push(temp1);
        s1.push(temp2);
    }
        while(!s1.empty())
        {

            temp1=s1.top();
            cout<<temp1->data<<" ";
            s1.pop();
        }

}
void connect_node_at_same_lvl(Node * root)
{
    Node *temp;
  queue <Node*> q1;
  q1.push(root);
  q1.push(NULL);
  while(!q1.empty())
  {
      temp=q1.front();
      q1.pop();
      if(temp==NULL&&q1.front()==NULL)
      {
          return;
      }
      if(temp==NULL)
      {

          q1.push(NULL);
      }
      else
      {
          temp->nextRight=q1.front();
          if(temp->left)
          q1.push(temp->left);
          if(temp->right)
          q1.push(temp->right);
      }
       cout<<"HI";
  }
}
void printSpecial(Node *root)
{
   if (root == NULL)
     return;
   Node *node = root;
   while (node != NULL)
   {
      printf("%d ", node->data);
      node = node->nextRight;
   }
   if (root->left)
     printSpecial(root->left);
   else
     printSpecial(root->right);
}
void printdiagonal(Node * root)
{
    Node * temp1;
    queue<Node*> q1;
    q1.push(root);
    q1.push(NULL);

    while(!q1.empty())
    {
        temp1=q1.front();
        q1.pop();
        if(temp1==NULL&&q1.front()==NULL)
            return ;
        else if(temp1==NULL)
        {
            q1.push(NULL);
            cout<<"\n";
        }
        else
        {
            while(temp1!=NULL)
            {
                cout<<temp1->data<<" ";
                q1.push(temp1->left);
                temp1=temp1->right;
            }
        }

    }


}
void printArray(int *A,int n)
{

    for(int i=0;i<=n;i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
}
void print_root_to_leaf_path(Node * root,int A[],int i)
{
    if(root==NULL)
        return ;
    else if(!root->left&&!root->right)
    {
         A[i]=root->data;
        printArray(A,i);
        return ;
    }
    A[i]=root->data;
    print_root_to_leaf_path(root->left,A,i+1);
    print_root_to_leaf_path(root->right,A,i+1);


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
int max_val(int a, int b)
{
    return a>b?a:b;
}
int diameter(Node * root)
{
    if(root==NULL)
        return 0;
    int lh=height(root->left);
    int rh=height(root->right);
    int ld=diameter(root->left);
    int rd=diameter(root->right);
    int f=max_val(lh+rh+1,max_val(ld,rd));
    return f;
}
void printLeftBoundry(Node * P)
{
    if(P)
    {
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

}
void printRightBoundry(Node * P)
{
    if(P)
    {
        if(P->right)
        {
            cout<<P->data<<" ";
            printRightBoundry(P->right);
        }
        else if(P->left)
        {
            cout<<P->data<<" ";
            printRightBoundry(P->left);
        }
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
    printLeftBoundry(root);
     // cout<<"\nLeaf node "<<endl;
    print_all_leaf_nodes(root);

   // cout<<"\nRight boundry "<<endl;
    printRightBoundry(root->right);

    return ;
}
int  sumLeftLeafNodes(Node * t,int *sum)
{
    if(t==NULL)
        return 0;
    if(t->left)
    {
        if(!t->left->left&&!t->left->right)
            *sum=*sum+t->left->data;
        sumLeftLeafNodes(t->left,sum);

    }
    if(t->right)
    {
     sumLeftLeafNodes(t->right,sum);
    }

}
bool isHeap(Node* t)
{bool l,r;
    if(!t->left&&!t->right)
        return true;
    else if(!t->right&&t->left)
    {
        if(t->left->data>t->data)
            return false ;
        else
            return true;

    }
     else if(t->right&&!t->left)
     {
         if(t->right->data>t->data)
            return false ;
        else
            return true;

     }
     else if(t->left&&t->right)
    {
        if(t->left->data>t->data||t->left->data>t->data)
        return false;
        else
            return true;
    }

       l= isHeap(t->left);
       r= isHeap(t->right);
       if(l&&r)
        return true;
       else false;

}
int find_sum_array(int A[],int n)
{
    int s=0;
    for(int i=0;i<=n;i++)
        s=s+A[i];
    return s;
}
void sum_root_to_leaf(Node* t , int A[], int i, int sum,int *out)
{
    int s;
    if(t==NULL) return ;
    else if(!t->left&&!t->right)
    {
        A[i]=t->data;
        s=find_sum_array(A,i);
        if(s==sum)
            {

                *out=1;
            }
    }
    A[i]=t->data;
    sum_root_to_leaf(t->left,A,i+1,sum,out);
    sum_root_to_leaf(t->right,A,i+1,sum,out);
}
void sumLeaves(Node* t,int *sum)
{

    if(t==NULL)
        return ;
     if(!t->left&&!t->right)
        {
            *sum=*sum+t->data;

        }
    sumLeaves(t->left,sum);
    sumLeaves(t->right,sum);
}
void storeLevel(Node * t , int i ,int *l,int key)
{
    if(t==NULL)
        return ;
    if(t->data==key)
    {
        *l=i;
    }
    storeLevel(t->left,i+1,l,key);
    storeLevel(t->right,i+1,l,key);

}
void kthdistanceRoot(Node * t , int i ,int key)
{
    if(t==NULL)
        return ;
    if(i==key)
    {
        cout<<t->data<<" ";
    }
     kthdistanceRoot(t->left,i+1,key);
    kthdistanceRoot(t->right,i+1,key);

}
void maxWidth(Node* t)
{
    Node *temp=NULL;
    int A[1000]={0};
    int i=0;
    int max=0;

    queue<Node*> q;
    q.push(t);
    q.push(NULL);
    while(!q.empty())
    {
       // cout<<"fucks";
        temp=q.front();
        if(temp)
        cout<<temp->data<<" ";
        q.pop();
         if(temp==NULL)
        {
            q.push(NULL);
            i++;
        }
        else if(temp==NULL&&q.front()==NULL)
        {
            return;
        }
        else
        {
            A[i]++;
            if(temp->left)
            q.push(t->left);
            if(t->right)
            q.push(temp->right);

        }
    }
    for(int k=0;k<=i;k++)
    {
        if(max<A[k])
            max=A[k];
    }
    cout<<max;

}
int  max_level_sum_in_BT(Node * t)
{

    int max=0,sum=0;
    queue<Node*> q;
    Node* temp;
    q.push(t);
    q.push(NULL);
    int count=0;
    while(!q.empty())
    {
        temp=q.front();
        if(temp!=NULL)
        {
           sum++;
        }
        q.pop();
        if(temp==NULL&&q.front()==NULL)
        {
            if(max<sum)
                max=sum;
            return max;
        }
        else if(temp==NULL)
        {
            q.push(NULL);
            if(max<sum)
                max=sum;
            sum=0;

        }
        else
        {
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
    }


}
void rightLeafSum(Node* t,int * sum)
{
    if(t==NULL)
        return ;
     if(t->left)
    {
        rightLeafSum(t->left,sum);

    }
    if(t->right)
    {
        if(!t->right->right&&!t->right->left)
        {
           *sum=*sum+t->right->data;
        }
        rightLeafSum(t->right,sum);
    }

}
void min_max(Node* t , int *min,int *max)
{
    if(t==NULL)
        return;
    if(t->data>*max)
       *max=t->data;
    if(t->data<*min)
        *min=t->data;
    min_max(t->left,min,max);
    min_max(t->right,min,max);
}
void countNonLeafNodes(Node * t)
{

}
void leftViewBT(Node* t)
{

    if(t==NULL)
        return ;
    cout<<t->data<<" ";
    if(t->left)
        leftViewBT(t->left);
    else if(t->right)
    {
        leftViewBT(t->right);
    }
}
void leftView(Node * t)
{
    Node* temp;
    queue<Node*> q;
    q.push(t);
    q.push(NULL);
    cout<<t->data<<" ";
    while(!q.empty())
    {
        temp=q.front();
        q.pop();
        if(temp==NULL&&q.front()==NULL)
            return ;
        else if(temp==NULL)
        {
            cout<<q.front()->data<<" ";
            q.push(NULL);

        }
        else
            {
                if(temp->left)
                q.push(temp->left);
                if(temp->right)
                q.push(temp->right);
        }
    }

}
void inOrder(Node* root,vector<int> &v)
{
    if(root==NULL)
    return ;
    inOrder(root->left,v);
    v.insert(v.end(),root->data);
    inOrder(root->right,v);

}
bool isBST(Node* root) {
    bool f=false;

    vector<int> v;
    inOrder(root,v);
    for(int i=0;i<v.size()-1;i++)
    {
        if(v[i]>v[i+1])
        {
            f=true;
            break;
        }
    }
    if(f==true)
    return false;
    else return true;


}
void vot(Node * t, int key,multimap<int , int> &m1)
{
   if(t==NULL)
    return ;
    m1.insert(pair<int , int>(key,t->data));
    vot(t->left,key-1,m1);
    vot(t->right,key+1,m1);
}
void verticalOrder(Node* t)
{
    multimap<int , int> m1;
    vot(t,0,m1);
    for(auto it=m1.begin();it!=m1.end();it++)
    {
        cout<<it->second<<" ";
    }
}
int  returnLevelOfNode(Node* t,int i, int key)
{
    if(t==NULL)
        return 0;
    if(key==i)
        {
            return i;
        }
    returnLevelOfNode(t->left,i+1,key);
    returnLevelOfNode(t->left,i+1,key);
}
int checkCousin(Node* t, int d1,int d2)
{
    int i=returnLevelOfNode(t,0,d1);
    int j=returnLevelOfNode(t,0,d2);
    if(i!=-1&&j!=-1)
    {
        if(i==j)
        {
            return 1;
        }
        else
            return 0;
    }
}
void rightView(Node *t)
{
     Node* temp;
    queue<Node*> q;
    q.push(t);
    q.push(NULL);
    while(!q.empty())
    {
        temp=q.front();
        q.pop();
        if(temp==NULL&&q.front()==NULL)
            return ;
        else if(temp==NULL)
        {

            q.push(NULL);

        }
        else
            {
                if(!q.front())
                cout<<temp->data<<" ";
                if(temp->left)
                q.push(temp->left);
                if(temp->right)
                q.push(temp->right);
        }
    }
}
void tiltBT(Node* t,int *sum)
{
    int l,r;
    if(!t->left&&!t->right)
        return ;
    l=sum_node(t->left);
    r=sum_node(t->right);
    *sum=*sum+abs(l-r);
    tiltBT(t->left,sum);
    tiltBT(t->right,sum);
}
void findLeafAtMinLevel(Node* t,int i,int *min)
{
    if(t==NULL)
        return ;
    if(!t->left&&!t->right)
    {
        if(*min>i)
            *min=i;
    }
    findLeafAtMinLevel(t->left,i+1,min);
    findLeafAtMinLevel(t->right,i+1,min);
}
void sumLeafAtMinLevel(Node * t,int *sum,int i,int min)
{
    if(t==NULL)
        return ;
    if(!t->left&&!t->right)
    {
        if(i==min)
            *sum=*sum+t->data;
    }
    sumLeafAtMinLevel(t->left,sum,i+1,min);
    sumLeafAtMinLevel(t->right,sum,i+1,min);

}
void sumMinLeaves(Node * root)
{
    int min=999999,sum=0;
    findLeafAtMinLevel(root,0,&min);
    cout<<min<<" ";
    sumLeafAtMinLevel(root,&sum,0,min);
    cout<<sum<<" ";
}
int printAllAncestor(Node* t, int data)
{
    int l=1,r=1;
    if(t!=NULL)
    {
        if(t->data==data)
        {
            return 1;

        }
       l= printAllAncestor(t->left,data);
       r= printAllAncestor(t->right,data);
        if(l||r)
        {
            cout<<t->data<<" ";
            return 1;
        }

    }
    return 0;
}
bool identicalTree(Node* t1,Node* t2)
{
    bool l,r;
    if((!t1->left&&!t1->right)&&(!t2->left&&!t2->right))
    {
        if(t1->data==t2->data)
        {
            return true;
        }
        else
            return false;
    }
    else if((t1->left&&!t1->right)&&(t2->left&&!t2->right))
    {
        if(t1->left->data!=t2->left->data)
        return false;
        else
        {
            identicalTree(t1->left,t2->left);
        }



    }
    else if((!t1->left&&t1->right)&&(!t2->left&&t2->right))
    {
        if(t1->right->data!=t2->right->data)
        return false;
        else
        {
            identicalTree(t1->right,t2->right);
        }
    }
    else if((t1->left&&t1->right)&&(t2->left&&t2->right))
    {
        l=identicalTree(t1->left,t2->left);
        r=identicalTree(t1->right,t2->right);
        if(l&&r)
            return true;
        else
            return false;


    }
    else
        return false;
}


bool checkMirrorTree(Node* t1,Node* t2)
{
    bool l,r;
    if((!t1->left&&!t1->right)&&(!t2->left&&!t2->right))
    {
        if(t1->data==t2->data)
        {
            return true;
        }
        else
            return false;
    }
    else if((t1->left&&!t1->right)&&(t2->left&&!t2->right))
    {
        if(t1->left->data!=t2->left->data)
        return false;
        else
        {
            checkMirrorTree(t1->left,t2->left);
        }
    }
    else if((!t1->left&&t1->right)&&(!t2->left&&t2->right))
    {
        if(t1->right->data!=t2->right->data)
        return false;
        else
        {
            checkMirrorTree(t1->right,t2->right);
        }
    }
    else if((t1->left&&t1->right)&&(t2->left&&t2->right))
    {
        l=checkMirrorTree(t1->left,t2->left);
        r=checkMirrorTree(t1->right,t2->right);
        if(l&&r)
            return true;
        else
            return false;
    }
    else
        return false;
}

void mirror(Node* t)
{
    Node *temp;
     if(t==NULL)
     return ;
     mirror(t->left);
     mirror(t->right);
     temp=t->left;
     t->left=t->right;
     t->right=temp;
}
void storeAllParent(Node* t, int n, vector<Node*> &v)
{
    if(t==NULL||t->data==n)
      return ;
    else if(t->data>n)
    {
        v.insert(v.end(),t);
        storeAllParent(t->right,n,v);
    }
    else if(t->data<n)
    {
       v.insert(v.end(),t);
       storeAllParent(t->left,n,v);
    }
}
Node* LCA2(Node *root, int n1, int n2)
{
    vector<Node*> v1,v2;
    storeAllParent(root,n1,v1);
    storeAllParent(root,n2,v2);
    int i=0;
    Node *l=NULL;
    int a=v1.size();
    int b=v2.size();
    int size=a<b?a:b;
    while(v1[i]==v2[i])
    {
       // cout<<v1[i]<<"-----"<<v2[i]<<endl;
        l=v1[i];
        i++;
    }
    return l;
}
int count_Nodes(Node * t)
{
    if(t==NULL)
        return 0;
    if(!t->left&&!t->right)
    {
        return 1;
    }
    return count_Nodes(t->left)+count_Nodes(t->right)+1;
}
void search_node(Node* t, int val,Node*& temp)
{
    if(t==NULL)
    return ;
    if(t->data==val)
    {
        temp=t;
    }
    search_node(t->left,val,temp);
    search_node(t->right,val,temp);
}
bool isSubtree(Node*  T1 ,Node * T2)
{
     int c1=count_Nodes(T1);
     int c2=count_Nodes(T2);

     if(c1>=c2)
     {
         Node* temp=NULL;
         search_node(T1,T2->data,temp);
         cout<<"temp : "<<temp->data;
         if(temp)
            return identicalTree(temp,T2);
            else
                return false;

     }
     else
    {
        Node* temp=NULL;
        search_node(T2,T1->data,temp);
        if(temp)
            return identicalTree(temp,T1);
            else
            return false;
     }
}
void left_and_right_Most(Node *t)
{
    Node* temp;
    queue<Node*> q;
    q.push(t);
    q.push(NULL);
    while(!q.empty())
    {
        temp=q.front();
        q.pop();
        if(temp==NULL&&q.front()==NULL)
        {
            break;
        }
        else if(temp==NULL)
        {
            cout<<q.front()->data<<" ";
            q.push(NULL);
        }
        else
        {
            if(q.front()==NULL)
            {
                cout<<temp->data<<" ";
            }
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
    }
}
void returnSubTree(Node* t, int k,int &i)
{
    if(t==NULL)
    return ;
    if(k==sum_node(t))
    {
        i++;
    }
    returnSubTree(t->left,k,i);
    returnSubTree(t->right,k,i);
}
void countSiblingNodes(Node *node)
{
     if(node==NULL)
      return ;
   if(!node->left&&node->right)
   {
       cout<<node->left->data<<" ";
   }
   if(!node->right&&node->left)
   {
      cout<<node->left->data<<" ";
   }
   if(!node->right&&!node->left)
   {
       cout<<node->data<<" ";
   }
   countSiblingNodes(node->left);
   countSiblingNodes(node->right);
}
int  countLeaves(Node* t)
{
    if(t==NULL)
    return 0;
    if(!t->left&&!t->right)
    {
        return 1;
    }
    return countLeaves(t->left)+countLeaves(t->right);
}
void bt(Node* ptr, int k,int &i)
{
    if(ptr==NULL)
    return;
    int l=countLeaves(ptr);
    if(k==l)
    {
        i++;
        cout<<ptr->data<<" ";
    }
    bt(ptr->left,k,i);
    bt(ptr->right,k,i);
}
void btWithKleaves(Node *ptr, int k)
{
    int t=-1;
    bt(ptr,k,t);
    if(t==-1)
    {
        cout<<-1;
    }
    cout<<endl;
}

int kth(Node* t, int val,int k,vector<int> &v)
{
    int l,r;
    if(t==NULL)
        return 0;
    if(t->data==val)
        return 1;
    l=kth(t->left,val,k,v);
    r=kth(t->right,val,k,v);
    if(l||r)
    {
        if(t)
        v.insert(v.end(),t->data);
    }
}
int kthAncestor(Node *root, int k, int node)
{
    vector<int> v;
    kth(root,node,k,v);
    if(k>v.size()||v.size()==0||k==0)
    return -1;
    else
    return v[k-1];

}
int storeAllAncestorOfNode(Node* t,int val,vector<int> &v)
{
     int l,r;
    if(t==NULL)
        return 0;
    if(t->data==val)
        return 1;
    l=storeAllAncestorOfNode(t->left,val,v);
    r=storeAllAncestorOfNode(t->right,val,v);
    if(l||r)
    {
        if(t)
        v.insert(v.end(),t->data);
    }
}
 int main()
{
    int G[100];
    int sum=0;
    int A[]={50,14,8,23,18,56,45,83,99};
    int B[]={15,25,22,29,24,27,23,7,4,10,6,5,9};
    int C[]={17,7,25,5,9,21,28};
    int D[]={4,3,5};
    createWithArray(C,7);
   printf("Max Node Value :-%d",max_node(root));
    printf("\nSum Node Value :-%d",sum_node(root));
    printf("\n %d :- ",ls(root));
    printf("\nSearched Value : %d\n",search(root,2));
   // print_left_leaf(root);
    printf("%d ",print_left_leaf(root));
    printf("\nCheck Binary Tree : %d",isFullTree(root));
    cout<<"Level Order Traversal in Spiral Order "<<endl;
    printSpiral(root);
    cout<<"\nReverse Level Order Traversal "<<endl;
    ReverseLevelOrderTraversal(root);
    cout<<"\nPerfect Binary Tree Specific Level Order Traversal ";
    Pblvl(root);
    cout<<"\n Perfect Binary Specific Level Order traversal Set 2"<<endl;
    plsv_set_2(root);
    cout<<"\n Connected Nodes at Same Level "<<endl;
    connect_node_at_same_lvl(root);
    printSpecial(root);
    cout<<"\nPrinting the diagonal Element "<<endl;
    printdiagonal(root);
    cout<<"\n All the path from the root to the leaf\n";
    print_root_to_leaf_path(root,G,0);
    cout<<"Height of the tree : "<<height(root)<<endl;
    cout<<"Diameter of the tree : "<<diameter(root)<<endl;
    cout<<"Boundry Order Traversal "<< endl;
    BoundryTraversal(root);
    cout<<"\n Is Heap "<<isHeap(root);
    int s=0;
    cout<<"\n Sum of Leaves :";
    sumLeaves(root,&s);
    cout<<s;
    cout<<"\n sum of path from root to the leaf ";
    int out=0;
    sum=29;
    sum_root_to_leaf(root,G,0,sum,&out);
    cout<<out;
    cout<<"\n Level Of a Node :";
    int temp;
    storeLevel(root,1,&temp,7);
    cout<<temp;
    cout<<"\n Node kth dispance from the root ";
    kthdistanceRoot(root,0,1);

    cout<<"\nMax level sum in Binary Tree : ";
    cout<<max_level_sum_in_BT(root);
    int rsum=0;
    cout<<"\n Sum of Right Leaves Nodes :";
    rightLeafSum(root,&rsum);
    cout<<rsum;
    int lsum=0;
    cout<<"\n sum of Left leaves Nodes :";
    sumLeftLeafNodes(root,&lsum);
    cout<<lsum;
    int min=99999999,max=-13948324;
    cout<<"\n Min and Max in binary Tree are : ";
    min_max(root,&min,&max);
    cout<<min<<" "<<max<<endl;
    cout<<"Left view of Binary Tree : ";
    leftViewBT(root);
    cout<<"\nRight View of tree ";
    leftView(root);
    cout<<"\nIs BST :- "<<isBST(root);
    cout<<"\n Vectical Order Traversal :- "<<endl;
    verticalOrder(root);
    cout<<"\n check Cousin :- ";
    cout<<checkCousin(root,21,28);
    cout<<"\n Right View :";
    rightView(root);
    int tilt=0;
    cout<<"\nTilt of a Binary Tree : ";
    tiltBT(root,&tilt);
    cout<<tilt;
    cout<<"\n Sum of min root leaves ";
    sumMinLeaves(root);
    cout<<"\nAll ancestor Node ";
    printAllAncestor(root,5);
    Node *temp_var=NULL;
    cout<<"\n search Node :";
    search_node(root,7,temp_var);
    cout<<temp_var->data;
    cout<<"\nIs Identical : "<<identicalTree(root,root);
  //  cout<<"\n Common Ancestor : "<<endl;
    //cout<<LCA2(root,5,9)->data;
    cout<<"\n Is SUBTREE : "<<isSubtree(root,root->left->right);
    cout<<"\n Number of Nodes in the tree :"<<count_Nodes(root);
    cout<<"\n left Right Most :";
    left_and_right_Most(root);
    cout<<"\n Nunber pf subtree with a given sum :";
    int num=0;
    returnSubTree(root,21,num);
    cout<<num<<endl;
    cout<<"\n Spiral traversal ";
    printSpiral(root);
    cout<<"\n Boundry Traversal "<<endl;
    BoundryTraversal(root);
    cout<<"Noof Leaves Node : "<<countLeaves(root);
    cout<<"\n Binary Tree with k Leaves ";
    btWithKleaves(root,2);

   // cout<<"\nMax Width : ";
   // maxWidth(root);
   // linebyline(root);
// root->right->data=-4;
// cout<<"AAAAAAAAAAAAAA:- "<<checkBST(root);
   // Node* t=LCA(root,2,8);
   // if(t!=NULL)
  //  printf("\n LeastCommon Ancesstor : %d",LCA(root,3,2));
    //inOrderNonRecursive(root);
    //  printf("\nPreOrder Traversal :-");
   // preOrder(root);
    // printf("\nNon Recursive :-\n");
    // root=delete_Node(root,82);
    // printf("\nAfter Deletion:-");
    // inOrderNonRecursive(root);
    // preOrder(root);
    //nonRecursivePreOrder(root);
    //printf("\nMax :-%d",findMax(root)->data);
    //printf("\nLevel Order Traversal :-");
    //level(root);


    return 0;
}



/*void verticleOrderTraversal(Node * t)
{
    Node* temp=NULL;
    int key=0;
    multimap<int,int> m1;
    queue<Node*> q1;
    q1.push(t);
    m1.insert(pair<int, int >(key,t->data));
    while(!q1.empty())
    {

        temp=q1.front();
      //  cout<<temp->data<<" ";
        q1.pop();
        if(temp->left)
        {
            q1.push(temp->left);
            key=key-1;
            m1.insert(pair<int, int >(key,temp->left->data));
        }
        if(temp->right)
        {
            q1.push(temp->right);
            key=key+1;
            m1.insert(pair<int, int >(key,temp->right->data));
        }
    }
    multimap<int , int>::iterator it;
    for( it=m1.begin();it!=m1.end();++it)
    {
        //cout<<"Hello World";
      cout<<it->first<<" "<<it->second<<endl;
    }
}
*/
