#include <iostream>

using namespace std;


#define MAX 20
int stack[MAX];
int top = -1;

void push(int x) {
    if (top == MAX - 1) {
        cout << "\nSTACK OVERFLOW";
        return;
    }
    stack[++top] = x;
}

int pop() {
    if (top == -1) {
        cout << "\nSTACK UNDERFLOW";
        return -1;
    }
    return stack[top--];
}

int evaluate(char exp[]) {
    int i = 0;
    while (exp[i] != '\0') {
        if (exp[i] == ' ') {
            i++;
            continue;
        }

        if (isdigit(exp[i])) {
            int num = 0;
            while (isdigit(exp[i])) {
                num = num * 10 + (exp[i] - '0');
                i++;
            }
            push(num);
        } else {
            int num2 = pop();
            int num1 = pop();
            int result = 0;

            if (exp[i] == '+') {
                result = num1 + num2;
            } else if (exp[i] == '-') {
                result = num1 - num2;
            } else if (exp[i] == '*') {
                result = num1 * num2;
            } else if (exp[i] == '/') {
                if (num2 == 0) {
                    cout << "\nError: Division by zero!";
                    return -1;
                }
                result = num1 / num2;
            }
            push(result);
            i++;
        }
    }
    return pop();
}

int main() {

    char postfixExpr[100];
    cout << "\nEnter a Postfix Expression: ";
    cin.getline(postfixExpr, 100);

    int result = evaluate(postfixExpr);
    cout << "\nThe Result: " << result;

   return 0;
}
