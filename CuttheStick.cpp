#include<iostream>
#include<algorithm>
#include<list>
using namespace std;
int main()
{
    list<int> l1;
    int n,val;
    list<int>::iterator it,minit;
    cin>>n;
    for(int  i=0;i<n;i++)
    {
        cin>>val;
        l1.insert(l1.end(),val);
    }
    for(auto it=l1.begin();it!=l1.end();++it)
    {
       minit=min_element(l1.begin(),l1.end());
       for(auto i2=l1.begin();i2!=l1.end();++i2)
       {
           if(*minit!=*i2)
           {
           *i2=*i2-*minit;
           }
           else if(*minit==*i2)
           {
               l1.remove(*minit);
           }
       }
       cout<<l1.size();
    }

    return 0;
}
