#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
  char str[100];
  cin>>str;
  unique(str,str+5);
  cout<<str;
  return 0;
}
