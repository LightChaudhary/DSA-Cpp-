#include<iostream>
#include<stack>
using namespace std;

bool isDigit(char c){
    return (c >= '0' && c <= '9');
}

int EvaluatePostfix(string exp){
    stack<int>st;

    for(char c: exp){
        if(isDigit(c)){
            st.push(c - '0');
        }
        else{
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            
            switch(c){
                case '+' : st.push(a+b);break;
                case '-' : st.push(a-b);break;
                case '*' : st.push(a*b);break;
                case '/' : st.push(a/b);break;
            }
        }
    }
    return st.top();
}

int main(){
    string exp;

    cout << "Enter postfix: ";
    cin >> exp;

    cout << "Evaluation: " << EvaluatePostfix(exp);

    return 0;
}