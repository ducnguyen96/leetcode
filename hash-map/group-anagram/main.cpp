#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    if (strs.size() == 1) {
      return {{strs[0]}};
    }

    unordered_map<string, vector<string>> myMap;

    for (auto x : strs) {
      string word = x;
      sort(word.begin(), word.end());
      myMap[word].push_back(x);
    }

    vector<vector<string>> ans;
    for (auto x : myMap) {
      ans.push_back(x.second);
    }
    return ans;
  }
};

int main(int argc, char *argv[]) {
  auto sol = new Solution();

  vector<string> strs = {{"eat", "ate", "tan", "ate", "nat", "bat"}};

  sol->groupAnagrams(strs);

  for (const auto &str : strs) {
    cout << str << " ";
  }
  return 0;
}
