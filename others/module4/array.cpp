#include <stdexcept>

template <typename T> class Stack {
private:
  T *s;
  int N;
  int capacity;

public:
  Stack(int cap) : N(0), capacity(cap) { s = new T[capacity]; }
  ~Stack() { delete[] s; }

  bool isEmpty() { return N == 0; }

  void push(const T item) {
    if (N == capacity) {
      resize(2 * capacity);
    }
    s[N++] = item;
  }

  T pop() {
    if (isEmpty()) {
      throw std::out_of_range("Stack underflow");
    }
    T item = s[--N];
    s[N] = nullptr;
    if (N > 0 && N == capacity / 4) {
      resize(capacity / 2);
    }
    return item;
  }

  void resize(int capacity) {
    T *copy = new T[capacity];
    for (int i = 0; i < N; i++) {
      copy[i] = s[i];
    }
    delete[] s;
    s = copy;
  }
};

template <typename T> class Queue {
private:
  T *q;
  int N;
  int capacity;
  int first;
  int last;

public:
  Queue(int cap) : N(0), capacity(cap), first(0), last(0) {
    q = new T[capacity];
  }
  ~Queue() { delete[] q; }

  bool isEmpty() { return N == 0; }

  void enqueue(const T item) {
    if (N == capacity) {
      resize(2 * capacity);
    }
    q[last++] = item;
    if (last == capacity) {
      last = 0;
    }
    N++;
  }

  T dequeue() {
    if (isEmpty()) {
      throw std::out_of_range("Queue underflow");
    }
    T item = q[first];
    q[first] = nullptr;
    N--;
    first++;
    if (first == capacity) {
      first = 0;
    }
    if (N > 0 && N == capacity / 4) {
      resize(capacity / 2);
    }
    return item;
  }

  void resize(int capacity) {
    T *copy = new T[capacity];
    for (int i = 0; i < N; i++) {
      copy[i] = q[(first + i) % N];
    }
    delete[] q;
    q = copy;
    first = 0;
    last = N;
  }
};
