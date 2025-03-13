#include <iostream>

struct Node {
  int data;
  Node *next;

  Node(int value) : data(value), next(nullptr) {}
};

class Stack {
private:
  Node *top;

public:
  Stack() : top(nullptr) {}

  void push(int value) {
    Node *newNode = new Node(value);
    newNode->next = top;
    top = newNode;
  }

  void pop() {
    if (isEmpty()) {
      std::cout << "Stack underflow" << std::endl;
    }
    Node *temp = top;
    top = top->next;
    delete temp;
  };

  int peek() {
    if (isEmpty()) {
      std::cerr << "Stack is empty" << std::endl;
      return -1;
    }
    return top->data;
  }

  bool isEmpty() { return top == nullptr; }

  ~Stack() {
    while (!isEmpty()) {
      pop();
    }
  }
};

class Queue {
private:
  Node *first;
  Node *last;

public:
  Queue() : first(nullptr), last(nullptr) {}

  void enqueue(int value) {
    Node *newNode = new Node(value);
    if (first == nullptr) {
      first = last = newNode;
    } else {
      last->next = newNode;
      last = newNode;
    }
  }

  void dequeue() {
    if (isEmpty()) {
      std::cout << "Queue underflow" << std::endl;
    }
    Node *temp = first;
    first = first->next;
    delete temp;
  }

  bool isEmpty() { return first == nullptr; }
};
