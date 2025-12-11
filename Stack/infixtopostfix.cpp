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
    if(c == '*' || c == '/') return 2;
    if(c == '+' || c == '-') return 1;
    return 0;
}

string infixToPostfix(string infix){
    Stack st;
    string postfix = "";

    for (int i = 0; i < infix.length(); i++){
        char c = infix[i];
        if(isOperand(c)){
            postfix += c;
        }
        else if (c == '('){
            st.push(c);
        } 
        else if(c == ')'){
            while(!st.isEmpty() && st.peek() != '('){
                postfix += st.pop();
            }
            st.pop();
        }
        else {
            while(!st.isEmpty() && 
        precedence(st.peek()) >= precedence(c)){
            postfix += st.pop();
        }
        st.push(c);
        }

    }
    while(!st.isEmpty()){
        postfix += st.pop();
    }
    return postfix;
}

int main(){
    string infix;

    cout << "Enter infix: ";
    cin >> infix;

    cout << "Postfix: " << infixToPostfix(infix);
    return 0;
}