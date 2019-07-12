#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct Node{
  ll data;
  Node *left,*right;
};
Node *newNode(ll item)
{
    Node *temp =new Node;
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}
void insert(Node *root,ll a1,ll a2,char lr){
    if(root==NULL)
        return;
    if(root->data==a1){
        switch(lr){
            case 'L':root->left=newNode(a2);
            break;
            case 'R':root->right=newNode(a2);
            break;
        }
    }
    else{
        insert(root->left,a1,a2,lr);
        insert(root->right,a1,a2,lr);
    }
}
void inorder(Node *root){
    if(root==NULL)
    return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
bool ifCousin(Node *root,Node *a,Node *b);
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        Node *root=NULL;
        while(n--){
            ll a1,a2;
            char lr;
            cin>>a1>>a2;
            cin>>lr;
            if(root==NULL){
                root=newNode(a1);
                switch(lr){
                    case 'L':root->left=newNode(a2);
                    break;
                    case 'R':root->right=newNode(a2);
                    break;
                }
            }
            else{
                insert(root,a1,a2,lr);
            }
        }
        //inorder(root);
        //cout<<endl;
        ll x,y;
        cin>>x>>y;
        Node *a=newNode(x);
        Node *b=newNode(y);
        if(a->data==b->data){
            cout<<"0";
            continue;
        }
        ifCousin(root,a,b)?cout<<"1":cout<<"0";
    }
	return 0;
}


/*This is a function problem.You only need to complete the function given below*/
void returnParent(Node* t, Node* a,Node*& par)
{
    if(t==NULL)
        return ;
    if(t->left)
    if(t->left->data==a->data)
    par=t;
    if(t->right)
    if(t->right->data==a->data)
    par=t;
    returnParent(t->left,a,par);
    returnParent(t->right,a,par);

}
void returnLevel(Node* t, Node* a, int i, int &lvl)
{
    if(t==NULL)
    return ;
    if(t->data==a->data)
        lvl=i;
    returnLevel(t->left,a,i+1,lvl);
    returnLevel(t->right,a,i+1,lvl);
}
bool ifCousin(Node *root,Node *a,Node *b)
{
    cout<<endl;
    Node *par1,*par2;
    int lvl1=0,lvl2=0;
    returnParent(root,a,par1);
    returnParent(root,b,par2);
    returnLevel(root,a,0,lvl1);
    returnLevel(root,b,0,lvl2);
    if(lvl1==lvl2&&par1!=par2)
    {
        return true;
    }
    else
        return false;


}
