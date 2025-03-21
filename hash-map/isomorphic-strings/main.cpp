#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
  bool isIsomorphic(string s, string t) {
    unordered_map<char, char> charMap;
    for (int i = 0; i < s.size(); i++) {
      auto sCh = s[i];
      auto tCh = t[i];
      if (charMap.find(sCh) != charMap.end()) {
        if (charMap[sCh] != tCh) {
          return false;
        }
      } else {
        for (auto pair : charMap) {
          if (pair.second == tCh) {
            return false;
          }
        }
        charMap[sCh] = tCh;
      }
    }
    return true;
  }
};

int main(int argc, char *argv[]) {
  auto solution = new Solution();

  // vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
  auto rs = solution->isIsomorphic("egg", "add");
  cout << rs << endl;

  return 0;
}
