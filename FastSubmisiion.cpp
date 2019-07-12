#include<iostream>
#include<math.h>

using namespace std;
int ex(string str)
{
    char num[100];
    int i,k,val=0,j,g=0;
    for( i=0,k=0;str[i]!='\0';i++)
    {
        if(str[i]>='0'&&str[i]<='9')
        {
           num[k++]=str[i];
        }
    }
    num[k]='\0';
    for(i=k-1,j=0;i>=0;i--,j++)
    {
        g=((int)num[i]-48)*pow(10,j);
        val=val+g;

    }
    if(str[0]=='S')
    {
        val=-val;
    }
    return val;
}
int main()
{
    int t,n,x,i;
    cin>>t;
    string str;
    while(t--)
    {
        cin>>n>>x;
        int init=x;
        for(i=0;i<n;i++)
        {
             cin.ignore();
         getline(cin,str);
         init=init+ex(str);
         cout<<" init :"<<init<<"ficntion extraxtion :"<<ex(str);
        }

         if(init>x)
         {
             cout<<"Yes"<<endl;
         }
         else
         {
             cout<<"No"<<endl;
         }

    }
   return 0;
}
