#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;
/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
};
void append(struct Node** head_ref, struct Node **tail_ref,
           int new_data)
{
    struct Node* new_node = new Node;
    new_node->data  = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL)
       *head_ref = new_node;
    else
       (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}
/* Function to get the middle of the linked list*/
struct Node* deleteAllOccurances(struct Node *head,int );
void printList(Node *head)
{
   while (head != NULL)
   {
      cout << head->data << " ";
      head = head->next;
   }
   cout << " ";
}
/* Driver program to test above function*/
int main()
{
  int T,i,n,l;
  // TO BE REMOVED
  for (int i=0; i<2000; i++);
    cin>>T;
    while(T--){
    struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        for(i=1;i<=n;i++)
        {
            cin>>l;
            append(&head, &tail, l);
        }
	int kk;
	cin>>kk;
    head =deleteAllOccurances(head,kk);
    printList(head);
    }
    return 0;
}


/*This is a function problem.You only need to complete the function given below*/
/* Link list Node
struct Node
{
    int data;
    Node* next;
};*/
/*You are required to complete below method*/
Node* newNode(int val)
{
    Node* temp=new Node;
    temp->next=NULL;
    temp->data=val;
    return temp;
}
Node* deleteAllOccurances(Node *head,int x)
{
    Node* head1=NULL,*last1=NULL,*p=head;
    if(head==NULL)
    return NULL;
    while(p)
    {
        if(head1==NULL&&p->data!=x)
        {
           head1=newNode(p->data);
           last1=head1;
        }
        else
        {
            if(p->data!=x)
            {
                last1->next=newNode(p->data);
                last1=last1->next;

            }
        }
        p=p->next;
    }
    head=head1;
    return head;
}
