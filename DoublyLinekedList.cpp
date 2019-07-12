
#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	Node *left,*right;
};
struct Node* newNode(int data)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}
void insert(Node *root, int a1,int a2, char lr){
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
Node *convertToDLL(Node *root,Node **head_ref);
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		Node *root=NULL;
		while(n--){
			int a1,a2;
			char lr;
			cin>>a1>>a2;
			scanf(" %c",&lr);
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
		Node *head=NULL;
		root=convertToDLL(root,&head);
		while(head->right!=NULL){
			cout<<head->data<<" ";
			head=head->right;
		}
		cout<<head->data<<endl;
		while(head!=NULL){
			cout<<head->data<<" ";
			head=head->left;
		}
		cout<<endl;
	}
}

/*This is a function problem.You only need to complete the function given below*/
/*Complete the function below
Node is as follows:
struct Node{
	int data;
	Node *left,*right;
};
*/

Node *convertToDLL(Node *t,Node **head)
{
    if(t==NULL)
      return NULL;
    if(!t->left&&!t->right)
    {
        if(*head==NULL)
          {
              *head=newNode(t->data);
              return *head;
          }
        else
        {
            Node *temp=newNode(t->data);
            Node* r=*head;
            while(r->right!=NULL)
            {
                r=r->right;
            }
            r->right=temp;
            temp->left=r;
            return *head;

        }
    }
    convertToDLL(t->left,head);
    convertToDLL(t->right,head);

}
