#include <iostream>

class QuickUnion {
private:
  int id[10];
  int root(int i) {
    while (i != id[i]) {
      i = id[i];
    }
    return i;
  }

public:
  QuickUnion() {
    for (int i = 0; i < 10; i++) {
      id[i] = i;
    }
  }

  bool connected(int p, int q) { return root(p) == root(q); }

  void union_cmd(int p, int q) {
    int i = root(p);
    int j = root(q);
    id[i] = j;
  }
};

int main(int argc, char *argv[]) {
  QuickUnion qu;
  qu.union_cmd(4, 3);
  qu.union_cmd(3, 8);
  qu.union_cmd(6, 5);
  qu.union_cmd(9, 4);
  qu.union_cmd(2, 1);
  std::cout << qu.connected(0, 7) << std::endl;
  std::cout << qu.connected(8, 9) << std::endl;
  qu.union_cmd(5, 0);
  qu.union_cmd(7, 2);
  qu.union_cmd(6, 1);
  qu.union_cmd(1, 0);
  std::cout << qu.connected(0, 7) << std::endl;

  return 0;
}
