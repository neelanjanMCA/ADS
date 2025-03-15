#include <iostream>


using namespace std;
#define max 5


class stack{
int top,i,x;
int stk[20];
public:
 void push(int);
 int pop();
 void display();
 stack()
 {
 top=0;
 }
 };
 void stack::push(int x){
 if(top==max){
    cout<<"\nSTACK OVERFLOW\n";
    }
    else{
    top=top+1;
    stk[top]=x;
    }
    }
    int stack::pop()
    {
    int ele;
    if(top==0){
    cout<<"\nSTACK UNDERFLOW\n";
    return 0;
    }
    else{
    ele=stk[top];
    top=top-1;
    return ele;;
    }
    }
 void stack::display()
 { if(top==0){
   cout<<"\nSTACK UNDERFLOW\n";
   }
   else{
   cout<<"\nContents of Stack are\n";
   for(i=1;i<=top;i++){
    cout<<stk[i]<<"\n";

    }
    }
    }
int main()
{
stack s;
int item,ch;

while(1){
cout<<"\n1.Push \n 2.POP\n 3.Display\n 4.Exit\n";
cout<<"Enter Your Choice";
cin>>ch;
switch(ch){
case 1:cout<<"\nenter the Item to be Inseted\n";
      cin>>item;
      s.push(item);
      break;
case 2:item=s.pop();
	cout<<"\nDeleted\n";
	break;
case 3:s.display();
	break;
case 4: cout<< "\nExit\n";
	exit(0);

default:cout<< "\nINVALID OPTION\n";
	break;
}
}
return 0;
}
