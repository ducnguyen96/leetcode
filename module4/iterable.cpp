
#include <iostream>

// Node structure for linked list-based data structures
template <typename T> struct Node {
  T data;
  Node *next;
  Node(T value) : data(value), next(nullptr) {}
};

// Generic Iterable class
template <typename T> class Iterable {
public:
  class Iterator {
  private:
    Node<T> *current;

  public:
    Iterator(Node<T> *node) : current(node) {}

    bool operator!=(const Iterator &other) const {
      return current != other.current;
    }

    T operator*() const { return current->data; }

    Iterator &operator++() {
      if (current)
        current = current->next;
      return *this;
    }
  };

  virtual Node<T> *getHead() const = 0;

  Iterator begin() const { return Iterator(getHead()); }

  Iterator end() const { return Iterator(nullptr); }
};

// Stack class with linked list implementation
template <typename T> class Stack : public Iterable<T> {
private:
  Node<T> *top;
  size_t size;

public:
  Stack() : top(nullptr), size(0) {}
  ~Stack() {
    while (!isEmpty()) {
      pop();
    }
  }

  void push(T value) {
    Node<T> *newNode = new Node<T>(value);
    newNode->next = top;
    top = newNode;
    size++;
  }

  void pop() {
    if (isEmpty()) {
      throw std::out_of_range("Stack underflow");
    }
    Node<T> *temp = top;
    top = top->next;
    delete temp;
    size--;
  }

  T peek() const {
    if (isEmpty()) {
      throw std::out_of_range("Stack is empty");
    }
    return top->data;
  }

  bool isEmpty() const { return top == nullptr; }

  size_t getSize() const { return size; }

  Node<T> *getHead() const override { return top; }
};

// Queue class with linked list implementation
template <typename T> class Queue : public Iterable<T> {
private:
  Node<T> *front;
  Node<T> *rear;
  size_t size;

public:
  Queue() : front(nullptr), rear(nullptr), size(0) {}
  ~Queue() {
    while (!isEmpty()) {
      dequeue();
    }
  }

  void enqueue(T value) {
    Node<T> *newNode = new Node<T>(value);
    if (rear) {
      rear->next = newNode;
    } else {
      front = newNode;
    }
    rear = newNode;
    size++;
  }

  void dequeue() {
    if (isEmpty()) {
      throw std::out_of_range("Queue underflow");
    }
    Node<T> *temp = front;
    front = front->next;
    if (!front)
      rear = nullptr;
    delete temp;
    size--;
  }

  T peek() const {
    if (isEmpty()) {
      throw std::out_of_range("Queue is empty");
    }
    return front->data;
  }

  bool isEmpty() const { return front == nullptr; }

  size_t getSize() const { return size; }

  Node<T> *getHead() const override { return front; }
};

int main() {
  Stack<int> stack;
  stack.push(10);
  stack.push(20);
  stack.push(30);

  std::cout << "Stack elements: ";
  for (int value : stack) {
    std::cout << value << " ";
  }
  std::cout << std::endl;

  Queue<int> queue;
  queue.enqueue(1);
  queue.enqueue(2);
  queue.enqueue(3);

  std::cout << "Queue elements: ";
  for (int value : queue) {
    std::cout << value << " ";
  }
  std::cout << std::endl;

  return 0;
}
