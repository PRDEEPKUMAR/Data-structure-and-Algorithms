/*Strtol Strtod Strtok Strpbrk atoi atof Strspn Strcspn */
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
int main()
{
    char str[20];
    char *result=strtok(str," ");
    cin.getline(str,20);
    cout<<str<<endl;
    cout<<result;
    return 0;
}
