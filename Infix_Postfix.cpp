#include <iostream>
#include <cctype>
#include <stack>
#include <string>
using namespace std;

int eval(int op1, int op2, char operate) {
    switch (operate) {
        case '*': return op2 * op1;
        case '/': return op2 / op1;
        case '+': return op2 + op1;
        case '-': return op2 - op1;
        default : return 0;
    }
}

int getWeight(char ch) {
    switch (ch) {
        case '/':
        case '*': return 2;
        case '+':
        case '-': return 1;
        default : return 0;
    }
}

string infixToPostfix(const string& infix) {
    stack<char> s;
    string postfix = "";
    
    for (int i = 0; i < infix.length(); i++) {
        char ch = infix[i];

        if (isdigit(ch)) {
            postfix += ch;
        } else if (ch == '(') {
            s.push(ch);
        } else if (ch == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop();
        } else {
            while (!s.empty() && getWeight(s.top()) >= getWeight(ch)) {
                postfix += s.top();
                s.pop();
            }
            s.push(ch);
        }
    }
    
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }
    
    return postfix;
}

int evalPostfix(const string& postfix) {
    stack<int> s;
    for (char ch : postfix) {
        if (isdigit(ch)) {
            s.push(ch - '0');
        } else {
            int op1 = s.top(); s.pop();
            int op2 = s.top(); s.pop();
            int result = eval(op1, op2, ch);
            s.push(result);
        }
    }
    return s.top();
}

int main() {
    string infix;
    
    cout << "Enter the infix expression: ";
    cin >> infix;

    cout << "Infix Expression: " << infix << endl;
    
    string postfix = infixToPostfix(infix);
    
    cout << "Postfix Expression: " << postfix << endl;
    
    int result = evalPostfix(postfix);
    
    cout << "Evaluation Result: " << result << endl;
    
    return 0;
}
