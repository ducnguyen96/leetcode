#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
  bool isAnagram(string s, string t) {
    int sLength = s.length();
    int tLength = t.length();

    if (sLength != tLength) {
      return false;
    }

    unordered_map<char, int> myMap;

    for (auto ch : s) {
      myMap[ch]++;
    }

    for (auto ch : t) {
      if (myMap[ch] == 0) {
        return false;
      }
      myMap[ch]--;
    }

    return true;
  }
};
