#include<iostream>
#include<stack>
using namespace std;

bool isDigit(char c){
    return (c >= '0' and c <= '9');
}

int EvaluatePrefix(string exp){
    stack<int>st;

    for(int i = exp.length() - 1; i >= 0; i--){
        char c = exp[i];
        if(isDigit(c)){
            st.push(c - '0');
        }
        else {
            int a = st.top(); st.pop();
            int b = st.top(); st.pop();

            switch(c){
                case '+': st.push(a + b);break;
                case '-': st.push(a - b);break;
                case '/': st.push(a * b);break;
                case '*': st.push(a / b);break;
                case '^': st.push(a ^ b);break;
            }
        }
    }
    return st.top();
}

int main(){
    string exp;

    cout << "Prefix: ";
    cin >> exp;

    cout << "-" << EvaluatePrefix(exp);
    return 0;
}