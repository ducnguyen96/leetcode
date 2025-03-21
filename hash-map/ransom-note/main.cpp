#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
  bool canConstruct(string ransomNote, string magazine) {
    int rLength = ransomNote.length();
    int mLength = magazine.length();

    if (mLength < rLength) {
      return false;
    }

    unordered_map<char, int> myMap;

    for (auto ch : magazine) {
      myMap[ch]++;
    }

    for (auto ch : ransomNote) {
      if (myMap[ch] == 0) {
        return false;
      }
      myMap[ch]--;
    }

    return true;
  };
};
