#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
  bool wordPattern(string pattern, string s) {
    unordered_map<char, string> myMap;
    int pSize = pattern.size();
    int sSize = s.size();

    int left = 0;
    int right = 0;

    for (int i = 0; i < pSize; i++) {
      auto ch = pattern[i];

      while (true) {
        if (s[right] == ' ' || right == sSize) {
          break;
        }
        right++;
      }

      if (right == sSize && i < pSize - 1) {
        return false;
      }

      auto word = s.substr(left, right - left);

      if (myMap.find(ch) != myMap.end()) {
        if (myMap[ch] != word) {
          return false;
        }
      } else {
        for (auto pair : myMap) {
          if (pair.second == word) {
            return false;
          }
        }
        myMap[ch] = word;
      }

      right++;
      left = right;
    }

    return right == sSize + 1;
  }
};

int main(int argc, char *argv[]) {
  auto sol = new Solution();

  string p = "abba";
  string s = "dog cat cat dog";
  s = sol->wordPattern(p, s);
  cout << s;
  return 0;
}
