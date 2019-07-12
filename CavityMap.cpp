#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
using namespace std;
int main()
{
    int i,j,n;
    char A[101][101];
    cin>>n;
    char up,down,right,left;
    for(i=0;i<n;i++)
    {
        gets
    }
    if(n>2)
    {

    for(i=1;i<n-1;i++)
    {
        for(j=1;j<n-1;j++)
        {
            up=A[i-1][j];down=A[i-1][j];right=A[i][j+1];left=A[i][j-1];
            if(A[i][j]>up&&A[i][j]>down&&A[i][j]>right&&A[i][j]>left)
            {
                A[i][j]='X';
            }
        }
    }}
    for(i=0;i<n;i++)
    {
        cout<<A[i];
        cout<<endl;
    }

    return 0;
}
