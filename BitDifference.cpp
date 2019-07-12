#include<iostream>
#include<bits/stdc++.h>
using namespace std;
char* convert(int n)
{
    int g=n,i=0;
    char* str=new char[20];
    while(g>0)
    {
        if(g%2==0)
        {
            str[i]='0';
        }
        else
        str[i]='1';
        g=g/2;
        i++;
    }
    while(i<4)
    {
        str[i]='0';
        i++;
    }
    str[i]='\0';
   reverse(str,str+strlen(str));
   //cout<<str;
    return str;
}
int compare(char* s1,char* s2)
{
    int count =0;
    int i;
    for(i=0;s1[i]!='\0'&&s2[i]!='\0';i++)
    {
        if(s1[i]!=s2[i])
        {
            count =count +2;
        }
    }
    return count;
}
int main()
{
    int t;
    char* s1,*s2;
    cin>>t;
    while(t--)
    {
        int sum=0;
        int i,n,k,j;
        cin>>n;
        int A[n];
        for(i=0;i<n;i++)
        {
            cin>>A[i];
        }
        for(i=0;i<n-1;i++)
        {
            for(j=i+1;j<n;j++)
            {

            s1=convert(A[i]);
            s2=convert(A[j]);
            k=compare(s1,s2);

            //cout<<k;
            sum=sum+k;
           }


        }
        cout<<sum<<endl;

    }
    return 0;
}
