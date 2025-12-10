/*
    1. Stack using Array
        Concept - 
            * manual size stack
            * Uses a simple array + integer topindex
            * Operations: push, pop, peek
            * Overflow when top == size - 1
            * Underflow when top == -1
*/

#include<iostream>
using namespace std;

class Stack{
    int topindex, capacity, *arr;
    public: 
    Stack(int cap){
        capacity = cap;
        topindex = -1;
        arr = new int[capacity];
    }
    bool isEmpty(){
        return topindex == -1;
    }
    bool isFull(){
        return topindex == capacity - 1;
    }
    void push(int c){
        if(!isFull()){
            arr[++topindex] = c;
        }
        else{
        cout << "Stack overflow";
    }
    }
    int pop(){
        if(!isEmpty()){
            return arr[topindex--];
        }
        return -1;
    }
    int peek(){
        if(!isEmpty()){
            return arr[topindex];
        }
        return -1;
    }
};

int main(){
    Stack s(3);

    s.push(10);
    s.push(20);
    s.push(30);

    while (!s.isEmpty()){
        cout << s.peek() << " ";
        s.pop();
    }
    cout << endl;
    return 0;
}