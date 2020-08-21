#include<iostream>
#include "./my_stack.h"

using namespace std;

Stack::Stack(int s){
    this->top = -1;
    this->size = s;
    this->arr = new int [this->size];
    if(this->arr == nullptr){
        cout << "Not init" << endl;
    }
}

void Stack::print_values(){
    cout << "Top : " << top << endl <<
            "Size value : " << size << endl;
    cout << "Array" << endl;
    for(int i = 0; i <= top; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

bool Stack::isempty(){
    if(top == -1){
        return true;
    }
    return false;
}

bool Stack::isfull(){
    if(top + 1 == size){
        return true;
    }
    return false;
}

void Stack::push(int value){
    if(isfull()){
        cout << "Overflow" << endl;
    }
    else{
        top++;
        arr[top] = value;
    }
}

void Stack::pop(){
    if(isempty()){
        cout << "Underflow" << endl;
    }
    else{
        top--;
    }
}

int Stack::gettop(){
    if(isempty()){
        cout << "Stack empty" << endl;
        return -1;
    }
    return arr[top];
}