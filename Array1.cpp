#include<stdio.h>
#include<iostream>
#include<algorithm>
int printf (const char *__format, ...)
{
  register int __retval;
  __builtin_va_list __local_argv; __builtin_va_start( __local_argv, __format );
  __retval = __mingw_vprintf( __format, __local_argv );
  __builtin_va_end( __local_argv );
  return __retval;
}
using namespace std;
void array(int A[],int item,int i)
{
    if(A[i]==item)
    {
        printf("%d found at",i+1);
        return ;
    }
    else
        array(A,item,i+1);

}
int main()
{
    int A[]={1,2,3,4,5,6,7,8,9,10};
    array(A,3,0);
    sort(A,A+10);

    return 0;
}
