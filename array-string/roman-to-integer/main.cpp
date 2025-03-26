#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
  int romanToInt(string s) {
    unordered_map<char, int> myMap = {{'I', 1},   {'V', 5},   {'X', 10},
                                      {'L', 50},  {'C', 100}, {'D', 500},
                                      {'M', 1000}};
    int n = s.length();
    int sum = 0;
    int idx = 0;

    while (idx < n) {
      if (idx == n - 1 || myMap[s[idx]] >= myMap[s[idx + 1]]) {
        sum += myMap[s[idx]];
      } else {
        sum -= myMap[s[idx]];
        sum += myMap[s[idx + 1]];
        idx++;
      }
      idx++;
    }

    return sum;
  }
};
