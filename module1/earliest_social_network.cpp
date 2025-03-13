#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

class UnionFind {
private:
  vector<int> parent;
  vector<int> rank;
  int numComponents;

public:
  UnionFind(int n) {
    parent.resize(n);
    rank.resize(n, 0);
    numComponents = n;
    for (int i = 0; i < n; i++) {
      parent[i] = i;
    };
  }
  int find(int x) {
    if (parent[x] != x) {
      parent[x] = find(parent[x]);
    }

    return parent[x];
  }

  void union_cmd(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);

    if (rootX != rootY) {
      if (rank[rootX] < rank[rootY]) {
        parent[rootX] = rootY;
      } else if (rank[rootX] > rank[rootY]) {
        parent[rootY] = rootX;
      } else {
        rank[rootY] = rootX;
        rank[rootX]++;
      }
    }
  }

  int getNumComponents() const { return numComponents; }
};

int earliestConnectionTime(int n, const vector<tuple<int, int, int>> &log) {
  if (n <= 0)
    return -1;

  UnionFind uf(n);

  for (const auto &entry : log) {
    int timestamp = get<0>(entry);
    int u = get<1>(entry);
    int v = get<2>(entry);

    uf.union_cmd(u, v);

    if (uf.getNumComponents() == 1)
      return timestamp;
  }

  return -1;
}

int main(int argc, char *argv[]) {
  int n = 4;
  vector<tuple<int, int, int>> log = {{1, 0, 1}, {2, 2, 3}, {3, 0, 3}};

  int result = earliestConnectionTime(n, log);
  if (result != -1) {
    cout << "Earliest time all members are connected: " << result << endl;
  } else {
    cout << "All members never connected." << endl;
  }

  n = 3;
  log = {{1, 0, 1}}; // Only connects 0 and 1, not 2
  result = earliestConnectionTime(n, log);
  if (result != -1) {
    cout << "Earliest time all members are connected: " << result << endl;
  } else {
    cout << "All members never connected." << endl;
  }

  return 0;
}
