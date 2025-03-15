#include <iostream>

using namespace std;
# define MAX 100
int main()
{
    int n,low,high,mid,srch;
    int found =0;
    int a[MAX];
    cout<<"Enter the Size of array";
    cin>>n;
    cout<<"Enter the "<<n<<" elements";
    for(int i=0; i<n;i++){
        cin>>a[i];
    }
    cout<<"Enter the element to be found:";

    cin>>srch;

    low=0;
    high=n-1;
    while(low<=high){
        mid=int(low+high)/2;

        if(srch==a[mid]){

            cout<<"Element found at:"<<mid;
            found=1;
            break;
        }
        else if(a[mid]<srch){
            low=mid+1;
            }
        else{

            high=mid-1;
        }
    }
    if(found==0){
        cout<<"Element not found";
    }
return 0;
}

