#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  string longestCommonPrefix(vector<string> &strs) {
    string common = "";
    if (strs.size() == 1) {
      return strs[0];
    }

    int idx = 0;
    for (auto ch : strs[0]) {
      for (int i = 1; i < strs.size(); i++) {
        if (idx == strs[i].length()) {
          return common;
        }
        if (strs[i][idx] != ch) {
          return common;
        }
      }
      common += ch;
      idx++;
    }
    return common;
  }
};
