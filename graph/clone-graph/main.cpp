#include <unordered_map>
#include <vector>
using namespace std;

class Node {
public:
  int val;
  vector<Node *> neighbors;
  Node() {
    val = 0;
    neighbors = vector<Node *>();
  }
  Node(int _val) {
    val = _val;
    neighbors = vector<Node *>();
  }
  Node(int _val, vector<Node *> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};

class Solution {
private:
  unordered_map<int, Node *> myMap;

public:
  Node *cloneGraph(Node *node) {
    if (myMap.find(node->val) != myMap.end()) {
      return myMap[node->val];
    }
    auto n = new Node(node->val);
    myMap[node->val] = n;
    for (auto neighbor : node->neighbors) {
      n->neighbors.push_back(cloneGraph(neighbor));
    }
    return n;
  }
};
