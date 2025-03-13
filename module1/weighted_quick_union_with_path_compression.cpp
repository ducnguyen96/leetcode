#include <iostream>

class WeightedQuickUnion {
private:
  int id[10];
  int sz[10];
  int root(int i) {
    while (i != id[i]) {
      i = id[i];
    }
    return i;
  }

  int root_two_pass(int i) {
    // First pass: Find the root and store the path
    std::vector<int> path;
    int current = i;
    while (current != id[current]) {
      path.push_back(current); // Store the node in the path
      current = id[current];   // Move to the parent
    }
    int root = current; // This is the root

    // Second pass: Update each node in the path to point to the root
    for (int node : path) {
      id[node] = root;
    }

    return root;
  }

  int root_one_pass(int i) {
    while (i != id[i]) {
      id[i] = id[id[i]]; // Path compression
      i = id[i];
    }
    return i;
  }

public:
  WeightedQuickUnion() {
    for (int i = 0; i < 10; i++) {
      id[i] = i;
    }
  }

  bool connected(int p, int q) { return root(p) == root(q); }

  void union_cmd(int p, int q) {
    int i = root(p);
    int j = root(q);
    if (i == j)
      return;

    if (sz[i] < sz[j]) {
      id[i] = j;
      sz[j] += sz[i];
    } else {
      id[j] = i;
      sz[i] += sz[j];
    }
  }
};

int main(int argc, char *argv[]) {
  WeightedQuickUnion wqu;
  wqu.union_cmd(4, 3);
  wqu.union_cmd(3, 8);
  wqu.union_cmd(6, 5);
  wqu.union_cmd(9, 4);
  wqu.union_cmd(2, 1);
  std::cout << wqu.connected(0, 7) << std::endl;
  std::cout << wqu.connected(8, 9) << std::endl;
  wqu.union_cmd(5, 0);
  wqu.union_cmd(7, 2);
  wqu.union_cmd(6, 1);
  wqu.union_cmd(1, 0);
  std::cout << wqu.connected(0, 7) << std::endl;

  return 0;
}
