#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
  bool isValid(string s) {
    stack<char> st;
    for (auto ch : s) {
      if (ch == '(' || ch == '[' || ch == '{') {
        st.push(ch);
      } else if (st.size() == 0) {
        return false;
      } else if ((ch == ')' && st.top() == '(') ||
                 (ch == ']' && st.top() == '[') ||
                 (ch == '}' && st.top() == '{')) {
        st.pop();
      } else {
        return false;
      }
    }
    return st.size() == 0;
  }
};

int main(int argc, char *argv[]) {
  auto solution = new Solution();

  auto rs = solution->isValid("()");
  cout << rs << endl;

  return 0;
}
