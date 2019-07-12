#include<bits/stdc++.h>
using namespace std;
struct et
{
	char value;
	et* left, *right;
};
bool isOperator(char c)
{
	if (c == '+' || c == '-' ||
			c == '*' || c == '/' ||
			c == '^')
		return true;
	return false;
}
void inorder(et *t)
{
	if(t)
	{
		inorder(t->left);
		printf("%c ", t->value);
		inorder(t->right);
	}
}
et* newNode(int v)
{
	et *temp = new et;
	temp->left = temp->right = NULL;
	temp->value = v;
	return temp;
};
et* constructTree(char []);
int main()
{
    int t;
    cin>>t;
    while(t--){
    char postfix[25];
	cin>>postfix;
	et* r = constructTree(postfix);
	inorder(r);
	cout<<endl;
}
return 0;
}


//function to construct expression tree
typedef struct et Node;
et* constructTree(char str[])
{
    Node* temp=NULL,*t1=NULL,*t2=NULL;
    stack<et*> s;
    int i;
    for(i=0;str[i]!='\0';i++)
    {
        temp=newNode(str[i]);
        if(str[i]>=97&&str[i]<=122)
        {
            s.push(temp);
        }
        else if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/'||str[i]=='^')
            {
                t1=s.top();
                s.pop();
                t2=s.top();
                s.pop();
                temp->right=t1;
                temp->left=t2;
                s.push(temp);
            }
    }
    return s.top();
}
