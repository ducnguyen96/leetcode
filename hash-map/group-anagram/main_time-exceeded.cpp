#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    int size = strs.size();
    if (size == 1) {
      return {{strs[0]}};
    }
    vector<vector<string>> rs = {{strs[0]}};

    unordered_map<char, int> myMap;
    for (auto ch : strs[0]) {
      myMap[ch]++;
    }

    vector<unordered_map<char, int>> myMaps = {myMap};

    for (int i = 1; i < size; i++) {
      int validIdx = -1;
      for (int j = 0; j < myMaps.size(); j++) {
        if (strs[i].length() != rs[j][0].length()) {
          continue;
        }
        unordered_map<char, int> tmpMap = {};
        for (int k = 0; k < strs[i].size(); k++) {
          tmpMap[strs[i][k]]++;
        }

        auto match = true;
        for (auto iter = tmpMap.begin(); iter != tmpMap.end(); iter++) {
          if (iter->second != myMaps[j][iter->first]) {
            match = false;
            break;
          }
        }
        if (!match) {
          continue;
        } else {
          validIdx = j;
        }
      }
      if (validIdx != -1) {
        rs[validIdx].push_back(strs[i]);
      } else {
        rs.push_back({strs[i]});
        unordered_map<char, int> tmpMap = {};
        for (auto ch : strs[i]) {
          tmpMap[ch]++;
        }
        myMaps.push_back(tmpMap);
      }
    }

    return rs;
  }
};
