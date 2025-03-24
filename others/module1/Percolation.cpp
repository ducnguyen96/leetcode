#include <iostream>
#include <vector>
using namespace std;

class UnionFind {
private:
  vector<int> parent; // Mảng lưu cha của mỗi phần tử
  vector<int> rank;   // Mảng lưu độ cao của cây
public:
  UnionFind(int n) {
    parent.resize(n);
    rank.resize(n, 0);
    for (int i = 0; i < n; i++) {
      parent[i] = i;
    }
  }

  int find(int x) {
    if (parent[x] != x) {
      parent[x] = find(parent[x]);
    }
    return parent[x];
  }

  void union_command(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX == rootY)
      return;

    if (rank[rootX] < rank[rootY]) {
      parent[rootX] = rootY;
      rank[rootY] += rank[rootX];
    } else {
      parent[rootY] = rootX;
      rank[rootX] += rank[rootY];
    }
  };

  // Kiểm tra xem x và y có cùng tập hợp không
  bool connected(int x, int y) { return find(x) == find(y); }
};

class Percolation {
private:
  int N;
  std::vector<bool> openSites;
  UnionFind uf;
  int virtualTop;
  int virtualBottom;

  int xyTo1D(int row, int col) { return row * N + col; };

public:
  Percolation(int n) : N(n), openSites(n * n, false), uf(n * n + 2) {
    virtualTop = n * n;
    virtualBottom = n * n + 1;
  }

  void open(int row, int col) {
    // kiểm tra biên
    if (row < 0 || row >= N || col < 0 || col >= N) {
      cout << "Vị trí không hợp lệ!" << endl;
    }

    // Convert to 1D index
    int index = xyTo1D(row, col);

    // Nếu ô đã mở thì bỏ qua
    if (openSites[index])
      return;

    // Mở ô
    openSites[index] = true;

    // Kết nối với ô ảo nếu ở hàng đầu hoặc cuối
    if (row == 0)
      uf.union_command(index, virtualTop);

    if (row == N - 1)
      uf.union_command(index, virtualBottom);

    // Kết nối với các ô liền kề nếu chúng đã mở
    int directions[4][2] = {
        {-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // Trên, dưới, trái, phải
    for (auto &dir : directions) {
      int newRow = row + dir[0];
      int newCol = col + dir[1];
      if (newRow >= 0 && newRow < N && newCol >= 0 && newCol < N) {
        int neighborIndex = xyTo1D(newRow, newCol);
        if (openSites[neighborIndex]) {
          uf.union_command(index, neighborIndex);
        }
      }
    }
  }

  // Kiểm tra xem hệ thống có thấm không
  bool percolates() { return uf.connected(virtualTop, virtualBottom); }
};

int main() {
  int N = 3; // Lưới 3x3
  Percolation perc(N);

  // Mở một số ô để kiểm tra
  perc.open(0, 0); // Mở ô (0,0)
  perc.open(1, 0); // Mở ô (1,0)
  perc.open(2, 0); // Mở ô (2,0)

  // Kiểm tra xem hệ thống có thấm không
  if (perc.percolates()) {
    cout << "He thong tham!" << endl;
  } else {
    cout << "He thong chua tham!" << endl;
  }

  // Thử mở thêm ô
  perc.open(1, 1);
  if (perc.percolates()) {
    cout << "He thong tham!" << endl;
  } else {
    cout << "He thong chua tham!" << endl;
  }

  return 0;
}
