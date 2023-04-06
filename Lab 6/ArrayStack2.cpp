#include <iostream>
#include <chrono>
using namespace std::chrono;
using namespace std;

const int MAX_SIZE = 10;

int top = -1; // Initializing the top of the stack
int stack[MAX_SIZE];

bool isEmpty() { // Checking whether stack is empty
    return (top == -1);
}

bool isFull() { // Checking whether stack is full
    return (top == MAX_SIZE - 1);
}

void Push(int x) { // Adding an element into top of the stack
    if (isFull()) {
        cout << "Stack Overflow" << endl;
        return;
    }
    top++;
    stack[top] = x;
}

int Pop() { // Removing an element from the stack
    int value;
    if (isEmpty()) {
        cout << "Stack Underflow" << endl;
        return -1;
    }
    value = stack[top];
    top--;
    return value;
}

void Display() { // Displaying elements on the stack
    int i;
    if (top == -1) {
        cout << "Stack Underflow" << endl;
        return;
    }
    cout << "Stack : ";
    for (i =0; i <= top; i++) {
        cout << stack[i] << " ";
    }
    cout << endl;
}

int main() {

    auto start = high_resolution_clock::now();

    Push(8);
    Push(10);
    Push(5);
    Push(11);
    Push(15);
    Push(23);
    Push(6);
    Push(18);
    Push(20);
    Push(17);
    Display();
    Pop();
    Pop();
    Pop();
    Pop();
    Pop();
    Display();
    Push(4);
    Push(30);
    Push(3);
    Push(1);
    Display();

    // Calculating the time taken to execute
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken to execute: " << duration.count() << " microseconds" << endl;

    return 0;
}
