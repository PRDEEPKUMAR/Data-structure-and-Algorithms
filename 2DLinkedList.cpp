#include <bits/stdc++.h>
#define MAX 20
using namespace std;
struct Node
{
	int data;
	Node* right, *down;
};
void display(Node* head)
{
    Node* Rp;
	Node* Dp = head;
	while (Dp) {
		Rp = Dp;
		while (Rp) {
			cout << Rp->data << " ";
			Rp = Rp->right;
		}
		//cout << "
";
		Dp = Dp->down;
	}
}
Node* constructLinkedMatrix(int mat[MAX][MAX], int n);
// driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int mat[MAX][MAX];
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                cin>>mat[i][j];
        Node* head = constructLinkedMatrix(mat, n);
        if(!head)cout<<"-1";
	    else display(head);
	    cout<<"
";
    }
	return 0;
