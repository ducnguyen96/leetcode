using namespace std;

class MinStack {
private:
  int idx = -1;
  int values[3 * 10000];
  int mins[3 * 10000];

public:
  MinStack() {}

  void push(int val) {
    if (idx == -1) {
      mins[0] = val;
    } else {
      mins[idx + 1] = min(getMin(), val);
    }
    values[idx + 1] = val;
    idx++;
  }

  void pop() { idx--; }

  int top() { return values[idx]; }

  int getMin() { return mins[idx]; }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
