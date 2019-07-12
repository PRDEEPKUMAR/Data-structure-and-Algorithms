#include<iostream>
using namespace std;
int main()
{
    string str;
    int i,t,n,zero=0,one=0;
    cin>>t;
    while(t--){
            zero=0,one=0;
  cin>>str;
   for(i=0;str[i]!='\0';i++)
   {
       if(str[i]=='0')
        zero++;
       else
        one++;
   }
     if(one==1||zero==1)
     cout<<"YES"<<endl;
     else
        cout<<"NO"<<endl;


    }
  return 0;
}
