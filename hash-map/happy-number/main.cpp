#include <unordered_map>
using namespace std;

class Solution {
public:
  bool isHappy(int n) {
    unordered_map<int, bool> myMap = {{1, true}};

    int current = n;
    while (myMap[current] == false) {
      myMap[current] = true;

      int sum = 0;
      while (current >= 10) {
        int tmp = current % 10;
        sum += tmp * tmp;
        current /= 10;
      }

      sum += current * current;
      current = sum;
    }

    return current == 1;
  }
};

int main(int argc, char *argv[]) {
  auto sol = new Solution();

  sol->isHappy(19);
  return 0;
}
