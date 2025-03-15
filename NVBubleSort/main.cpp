#include <iostream>

using namespace std;

int main()
{
   int n;
    int a[5];
    int temp;

    cout<<"Enter the Size of array";
    cin>>n;
    for(int i=0; i<n;i++){
	cout<<"Enter the element"<<i+1<<":";
	cin>>a[i];
    }
    cout<<"\nUNSORTED ELEMENTS\n";
    for (int i = 0; i < n; i++) {
	cout << a[i] << " ";
    }

    for(int i=0;i<n-1;i++){
	for(int j=0;j<n-i-1;j++){
		if(a[j]>a[j+1]){
		temp=a[j];
		a[j]=a[j+1];
		a[j+1]=temp;
		}
		}
		}
    cout<<"\nSORTED ELEMENTS\n";
    for (int i = 0; i < n; i++) {

	cout << a[i] << " ";
    }
}
