#include <iostream>

class QuickFind {
private:
  int id[10];

public:
  QuickFind() {
    for (int i = 0; i < 10; i++) {
      id[i] = i;
    }
  }

  bool connected(int p, int q) { return id[p] == id[q]; }

  void union_cmd(int p, int q) {
    int pid = id[p];
    int qid = id[q];
    for (int i = 0; i < 10; i++) {
      if (id[i] == pid) {
        id[i] = qid;
      }
    }
  }
};

int main(int argc, char *argv[]) {
  QuickFind qf;
  qf.union_cmd(4, 3);
  qf.union_cmd(3, 8);
  qf.union_cmd(6, 5);
  qf.union_cmd(9, 4);
  qf.union_cmd(2, 1);
  std::cout << qf.connected(0, 7) << std::endl;
  std::cout << qf.connected(8, 9) << std::endl;
  qf.union_cmd(5, 0);
  qf.union_cmd(7, 2);
  qf.union_cmd(6, 1);
  qf.union_cmd(1, 0);
  std::cout << qf.connected(0, 7) << std::endl;

  return 0;
}
