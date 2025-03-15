
#include<iostream.h>
#include<conio.h>
#include<process.h>


void main(){

    int n;
    int item;
    int low;
    int high;
    int mid;
    int search;
    int found=0;
    int a[5];
    clrscr();
    cout<<"Enter the Size of array";
    cin>>n;
    for(int i=0; i<n;i++){
	cout<<"Enter the element"<<i+1<<":";
	cin>>a[i];
    }
    cout<<"Enter the Element to be searched";
    cin>>search;
    high=n-1;
    low=0;
    while (low<=high){
	mid = int(low + high) /2;
	if(a[mid]==search){
	    cout<<"Element found at index:"<<mid;
	    found=1;
	    break;
	 }
	else if (a[mid] < search){
	    low = mid + 1;
	 }
	else{
	   high = mid - 1;
	   }

     }

if(found==0){
    cout<<"Element not found";
}
getch();
}