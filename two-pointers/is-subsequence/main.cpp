#include <iostream>

using namespace std;

class Solution {
public:
  bool isSubsequence(string s, string t) {
    int sLength = s.length();
    int tLength = t.length();
    if (sLength > tLength) {
      return false;
    }

    int left = 0;
    int right = 0;
    while (right < tLength) {
      while (left < sLength && s[left] == t[right]) {
        left++;
        right++;
      }
      right++;
    }
    return left == sLength;
  }
};

int main(int argc, char *argv[]) {
  auto solution = new Solution();

  auto rs = solution->isSubsequence("axc", "ahbgdc");
  cout << rs << endl;

  return 0;
}
