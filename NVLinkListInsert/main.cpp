#include <iostream>

using namespace std;



class linked{
protected:
 struct node{
	int info;
	struct node *link;
	};
 typedef struct node Node;
 Node *start;
 public:
  void create();
  void display();
  void insert_beg();
  void insert_end();
  void insert_sp();

linked(){
 start=NULL;
 } };
void linked::create()
{
int item;
Node *ptr;
if(start==NULL){
ptr= new Node;
cout<<"\nEnter the item to the Node:";
cin>>item;
ptr->info=item;
ptr->link=NULL;
start=ptr;
}
else{
cout<<"\nLINK LIST ALREADY EXISTS\n";
}
}
void linked::display(){
 Node *ptr;
 if(start==NULL){
  cout<<"LINK LIST IS EMPTY";
  }
  else{
  ptr=start;
  while(ptr!=NULL){
   cout<<ptr->info<<"\t";
   ptr=ptr->link;
   }
   }
   }
void linked::insert_beg()
{
Node *ptr;
int item;
if(start==NULL){
ptr= new Node;
cout<<"\nEnter the item to the Node:";
cin>>item;
ptr->info=item;
ptr->link=NULL;
start=ptr;
}
else{
ptr= new Node;
cout<<"Enter the item";
cin>>item;
ptr->info=item;
ptr->link=start;
start=ptr;
}
}
void linked::insert_end(){
Node *ptr, *temp;
int item;
if(start!= NULL){
temp=start;
cout<<"Enter a item:";
cin>>item;
while(temp->link!=NULL){
temp=temp->link;
}
ptr= new node;
ptr->info=item;
ptr->link= NULL;
temp->link=ptr;
}
else{
ptr= new Node;
cout<<"\nEnter the item to the Node:";
cin>>item;
ptr->info=item;
ptr->link=NULL;
start=ptr;
}
}
void linked::insert_sp()
{
Node *temp;
Node *ptr;
int y, item;
if(start== NULL){
cout<<"Link list empty";
}
else if (start!=NULL){
 temp=start;
 cout<<"Enter the element after which item has to be inserted:";
 cin>>y;
 while(temp->info!=y && temp->link !=NULL){
  temp=temp->link;
  }
  if(temp->info==y){
  ptr= new Node;
  cout<<"Enter the item:";
  cin>>item;
  ptr->info=item;
  ptr->link=temp->link;
  temp->link=ptr;
  }
  else{
  cout<<"Element Not found";
  }
  }
  else{
  cout<<"Element not found";
  }
  }
int main(){
 linked l;
 int ch;

 while(1){
  cout<<"\n1.Create\n2.Display\n3.Inset Begin\n4.Insert End\n5.Inset Specified\n6.Exit\n";
  cout<<"ENter your Choice:";
  cin>>ch;
  switch(ch){
  case 1:l.create();
	 break;
  case 2:l.display();
	  break;
  case 3: l.insert_beg();
	  break;
  case 4:l.insert_end();
	 break;
  case 5:l.insert_sp();
	 break;
  case 6: exit(0);
	break;
  default:cout<<"INVALID CHOICE";
  break;
  }
  }
  return 0;
 }

