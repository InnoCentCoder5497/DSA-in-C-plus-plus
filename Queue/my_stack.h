#ifndef MY_STACK_H
#define MY_STACK_H

class Stack {
    private:
        int top;
        int size;
        int *arr;

    public:

        Stack(int);
        void print_values();
        bool isempty();
        bool isfull();
        void push(int);
        void pop();
        int gettop();
};
#endif