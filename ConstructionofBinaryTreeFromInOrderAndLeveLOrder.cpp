#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int key;
    struct Node* left, *right;
};
Node* newNode(int key)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->key = key;
    node->left = node->right = NULL;
    return (node);
}
Node* buildTree(int inorder[], int levelOrder[], int iStart, int iEnd,int n);
void printPreorder(Node* node)
{
    if (node == NULL)
       return;
    cout << node->key << " ";
    printPreorder(node->left);
    printPreorder(node->right);

}
int main()
{
    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;
    int in[n],level[n];
    for(int i=0;i<n;i++){
        cin>>in[i];
    }
    for(int i=0;i<n;i++){
        cin>>level[i];
    }
    Node *root=NULL;
    root = buildTree(in, level, 0, n - 1,n);
    printPreorder(root);
    cout<<endl;
    }
    return 0;
}




Node* buildTree(int inorder[], int levelOrder[],
                int iStart, int iEnd, int n)
{
    if (n <= 0)
          return NULL;

    // First node of level order is root
    Node* root = newNode(levelOrder[0]);

    // Search root in inorder
    int index = -1;
    for (int i=iStart; i<=iEnd; i++){
        if (levelOrder[0] == inorder[i]){
            index = i;
            break;
        }
    }

    // Insert all left nodes in hash table
    unordered_set<int> s;
    for (int i=iStart;i<index;i++)
        s.insert(inorder[i]);

    // Separate level order traversals
    // of left and right subtrees.
    int lLevel[s.size()];  // Left
    int rLevel[iEnd-iStart-s.size()]; // Right
    int li = 0, ri = 0;
    for (int i=1;i<n;i++) {
        if (s.find(levelOrder[i]) != s.end())
            lLevel[li++] = levelOrder[i];
        else
            rLevel[ri++] = levelOrder[i];
    }

    // Recursively build left and right
    // subtrees and return root.
    root->left = buildTree(inorder, lLevel,
                 iStart, index-1, index-iStart);
    root->right = buildTree(inorder, rLevel,
                  index+1, iEnd, iEnd-index);
    return root;

}
/*int search(int A[], int start, int end ,int val )
{

    for(int i=start;i<=end;i++)
    {

        if(A[i]==val)
        {
            return i;
        }
    }
    return -1;
}
int *extrackKeys(int in[], int level[], int m, int n)
{
    int *newlevel = new int[m], j = 0;
    for (int i = 0; i < n; i++)
        if (search(in, 0, m-1, level[i]) != -1)
            newlevel[j] = level[i], j++;
    return newlevel;
}
Node* BuildTree(int inOrder[],int level[],int start, int end,int n)
{
    if(start>end)
    {
        return NULL;
    }
    Node* temp=newNode(level[0]);
    if(start==end)
        {
            return temp;
        }
    int mid=search(inOrder,start,end,temp->key);
    int *l=extrackKeys(inOrder,level,mid,n);
    int *r=extrackKeys(inOrder+mid+1,level,n-mid-1,n);

    temp->left=BuildTree(inOrder,l,start,mid-1,n);
    temp->right=BuildTree(inOrder,r,mid+1,end,n);
        return temp;
}

Node* buildTree(int in[], int lvl[],int start, int end, int n)
{
    int pointer=0;
    return BuildTree(in,lvl,start,end,n);
}*/
