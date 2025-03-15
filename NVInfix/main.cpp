#include <iostream>

using namespace std;

char stack[20];
int top=-1;
class postfix{
public:
	void push(char x){
	stack[++top]=x;
	}
	char pop(){
	if(top==-1){
	return -1;
	}
	else{
	return stack[top--];
	}
	}
int priority(char x){
	if(x=='(') return 0;
	if(x=='+'|| x=='-') return 1;
	if(x=='*'|| x=='/') return 2;
	if(x=='^') return 3;
	return -1;
	}
	};
int main(){

postfix obj;
char exp[20];
char *e;
char x;
cout<<"\n Enter the Infix Expression\n";
cin>>exp;
e=exp;
cout<<"\n POSTFIX EXPRESION IS:\n";
while(*e!='\0'){
if(isalnum(*e)){
  cout<<*e;
  }
else if(*e=='('){
  obj.push(*e);
  }
else if(*e==')'){
while( (x= obj.pop())!='('){
cout<<x;
}
}
else{
while(top!=-1 && obj.priority(stack[top])>= obj.priority(*e)){
cout<<obj.pop();
}
obj.push(*e);
}
e++;
}
while(top!=-1){
cout<<obj.pop();
}
return 0;
}
