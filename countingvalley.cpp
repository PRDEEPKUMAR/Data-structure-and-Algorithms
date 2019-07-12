#include<iostream>
using namespace std;
int main()
{
    int n,sum=0,c=0,i;
    cin>>n;
    char str[n];
    cin>>str;
    for(i=0;str[i]!='\0';i++)
    {

        if(str[i]=='D'&&str[i+1]=='U')
            {
                cout<<"hi";
            c++;
        }
    }
    cout<<c;

    return 0;
}
