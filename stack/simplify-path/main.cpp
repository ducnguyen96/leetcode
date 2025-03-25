#include <string>
using namespace std;

class Solution {
public:
  string simplifyPath(string path) {
    int n = path.length();

    string stack[3000];
    int idx = 0;

    string tmp = "";
    int end = 0;

    while (end <= n) {
      if (end == n || path[end] == '/') {
        if (tmp == "..") {
          if (idx > 0) {
            idx--;
          }
        } else if (tmp != "" && tmp != ".") {
          stack[idx] = "/" + tmp;
          idx++;
        }
        tmp = "";
      } else {
        tmp += path[end];
      }
      end++;
    }

    string ans = "";
    for (int i = 0; i < idx; i++) {
      ans += stack[i];
    }

    return ans.length() ? ans : "/";
  }
};
