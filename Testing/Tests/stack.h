#ifndef TESTING_STACK_H
#define TESTING_STACK_H

#include <iostream>

using namespace std;

const int MAX_ARR_LENGTH = (int)1e6;

class arrayStack {
public:
    int *arr;
    int topIndex;

    arrayStack() {
        arr = (int *)(malloc(MAX_LENGTH * sizeof(arr)));
        topIndex = -1;
    };

    void push(int x) {
        topIndex += 1;
        arr[topIndex] = x;
    }

    int pop() {
        if (topIndex < 0) {
            return NULL;
        }
        topIndex -= 1;
        return arr[topIndex + 1];

    }

    ~arrayStack() {
        free(arr);
    }
};

#endif //TESTING_STACK_H
