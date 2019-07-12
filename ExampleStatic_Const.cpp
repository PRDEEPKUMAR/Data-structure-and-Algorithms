#include<iostream>
using namespace std;
int main()
{
    int num=1;
    int const *ptr=&num;
    //int *t=static_cast<int *>(ptr);
    int *t=const_cast<int*>(ptr);
    cout<<*t;
    return 0;
}
