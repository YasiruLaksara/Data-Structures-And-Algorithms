#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

struct node { //Defining a node to carry the data and a pointer to the next node
    int data;
    struct node* next;
};

struct Stack {   //Defining a stack struct to carry a pointer to the head and the top of the stack
    node* head;
    node* top;
};

void Push(Stack& S, int n) {       //Adding an element to the top nof the stack
    node* new_node = new node();     //Creating a new node
    new_node->data = n;

    if (S.head == NULL) {    // Checking whether the satck is empty and If the stack is empty, make the new node both the head and top of the stack
        S.head = new_node;
        S.top = new_node;
    }
    else {   // Otherwise,adding the new node to the top of the stack
        S.top->next = new_node;
        S.top = new_node;
    }
}

int Pop(Stack& S) {   //removing an element from the stack
    if (S.head == NULL) {  //Checking whether the stack is empty ,If the stack is empty, display an error message and return -1
        cout << "Stack Underflow" << endl;
        return -1;
    }

    int x = S.top->data;

    if (S.top == S.head) {   // If the stack only has one element, setting both the head and top to NULL
        S.top = NULL;
        S.head = NULL;
    }
    else {    // Otherwise, finding the second-to-last node in the stack and removing the top node
        node* tmp = S.head;
        while (tmp->next != S.top) { 
            tmp = tmp->next;
        }
        tmp->next = NULL; 
        S.top = tmp; 
    }

    return x;
}

int Peek(Stack S) {  //To return the top value of the stack
    if (S.head == NULL) {   // Checking whether satck is empty
        cout << "Stack Underflow" << endl;
        return -1;
    }
    return S.top->data;  // Return the data from the top node
}

void Display(Stack S) {   //Displaying elements on the stack from top to bottom
    node* temp = S.head;

    cout<<"Stack : ";

    if (temp == NULL) {    //Checking whether satck is empty
        cout << "Stack Underflow" << endl;
        return;
    }

    while (temp != NULL) {  // Traversing  the stack from top to bottom and displaying each element
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main() {

    Stack S;
    S.top = NULL;

    S.head = NULL;
   

    auto start = high_resolution_clock::now();

    Push(S, 8);
    Push(S, 10);
    Push(S, 5);
    Push(S, 11);
    Push(S, 15);
    Push(S, 23);
    Push(S, 6);
    Push(S, 18);
    Push(S, 20);
    Push(S, 17);
    Display(S);
    Pop(S);
    Pop(S);
    Pop(S);
    Pop(S);
    Pop(S);
    Display(S);
    Push(S, 4);
    Push(S, 30);
    Push(S, 3);
    Push(S, 1);
    Display(S);

    //Calculating the time taken to execute
    auto stop = high_resolution_clock :: now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken to execute: " << duration.count() << " microseconds" << endl;

    return 0;
}