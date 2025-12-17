#include<iostream>
using namespace std;

#define size 100

class Stack{
    public: 
    int topindex;
    char arr[size];
    Stack(){
        topindex = -1;
    }

    bool isEmpty(){
        return topindex == -1;
    }

    bool isFull(){
        return topindex == size - 1;
    }

    void push(char c){
        if(!isFull()){
            arr[++topindex] = c;
        }
    }

    char pop(){
        if(!isEmpty()){
            return arr[topindex--];
        }
        return '\0';
    }
    
    char peek(){
        if(!isEmpty()){
            return arr[topindex];
        }
        return '\0';
    }
};

bool isOperand(char c){
    return (c >= '0' && c <= '9') || 
    (c >= 'A' && c <= 'Z') || 
    (c >= 'a' && c <= 'z');
}

int precedence(char c){
    if(c == '^') return 3;
    if(c == '*' || c == '/')  return 2;
    if(c == '+' || c == '-')  return 1;
    return 0;
}

string reverseString(string c){
    int i = 0, j = c.length() - 1;
    while(i < j){
        swap(c[i], c[j]);
        i++, j--;
    }
    return c;
}

string infixToPrefix(string infix){
    Stack s;
    string prefix = "";

    for(int i = infix.length() - 1; i >= 0; i--){
        char c = infix[i];

        if(isOperand(c)){
            prefix += c;
        }
        else if(c == ')'){
            s.push(c);
        }
        else if(c == '('){
            while(!s.isEmpty() && s.peek() != ')'){
                prefix += s.pop();
            }
            s.pop();
        }
        else{
            while(
                !s.isEmpty() && 
                (
                    precedence(s.peek()) > precedence(c) || 
                    (precedence(s.peek()) == precedence(c) && c == '^')
                )
            ){
                prefix += s.pop();
            }
            s.push(c);
        }
    }
    while(!s.isEmpty()){
        prefix += s.pop();
    }
    prefix = reverseString(prefix);
    return prefix;
}

int main(){
    string infix;

    cout << "Enter infix: ";
    cin >> infix;

    cout << "Prefix: " << infixToPrefix(infix);
    return 0;
}