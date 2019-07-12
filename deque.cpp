#include <iostream>
#include <deque>

using namespace std;

void printKMax(int arr[], int n, int k){
	 deque<int> d;
	 int max;
	 for(int i=0;i<n;i++)
     {
         max=0;
        for(int j=i;j<k;j++)
        {
            if(max<arr[j])
                max=arr[j];
        }
        d.push_back(max);
     }
      for (auto it = d.begin(); it != d.end(); ++it)
        cout << ' ' << *it;

}

int main(){

	int t;
	cin >> t;
	while(t>0) {
		int n,k;
    	cin >> n >> k;
    	int i;
    	int arr[n];
    	for(i=0;i<n;i++)
      		cin >> arr[i];
    	printKMax(arr, n, k);
    	t--;
  	}
  	return 0;
}

