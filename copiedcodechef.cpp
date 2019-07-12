#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long int count(long long int n)
{
    if(n==1)
    return 1;
    if(n==2)
    return 2;

    return count(n-1)+count(n-2);
}
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    long long int n;
	    cin>>n;
	    int ans = count(n)%(1000000000+7);
	    cout<<ans<<endl;
	}
	return 0;
}
