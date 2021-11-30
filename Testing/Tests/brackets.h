#include <iostream>

using namespace std;

const unsigned int MAX_LENGTH = (int)1e4;

struct stack {
    char arr[MAX_LENGTH];
    int topIndex;

    stack() {
        topIndex = -1;
    };

    void push(char c) {
        topIndex += 1;
        arr[topIndex] = c;
    }

    char top () {
        return arr[topIndex];
    }

    void pop() {
        topIndex -= 1;
    }
};

bool check_brackets(string sequence) {
    struct stack myStack;

    for (char i : sequence) {
        switch (i) {
            case '(':
                myStack.push(i);
                break;
            case '[':
                myStack.push(i);
                break;
            case ')':
                if (myStack.top() == '(') {
                    myStack.pop();
                } else {
                    if (myStack.top() == '[') {
                        return false;
                    }
                    myStack.push(')');
                }
                break;
            case ']':
                if (myStack.top() == '[') {
                    myStack.pop();
                } else {
                    if (myStack.top() == '(') {
                        return false;
                    }
                    myStack.push(']');
                }
                break;
            default:
                break;
        }
    }
    if (myStack.topIndex == -1)
        return true;
    return false;
}
