#include <iostream>
#include <vector>

void printArray(const std::vector<int> &arr) {
  for (int num : arr) {
    std::cout << num << " ";
  }
  std::cout << std::endl;
}

void selectionSort(std::vector<int> &arr) {
  int n = arr.size();
  for (int i = 0; i < n - 1; i++) {
    int minIndex = i;
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[minIndex]) {
        minIndex = j;
      }
    }
    std::swap(arr[i], arr[minIndex]);
  }
}

void insertionSort(std::vector<int> &arr) {
  int n = arr.size();
  for (int i = 1; i < n; i++) {
    int key = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
  }
}

void shellSort(std::vector<int> &arr) {
  int n = arr.size();
  for (int gap = n / 2; gap > 0; gap /= 2) {
    printArray(arr);
    for (int i = gap; i < n; i++) {
      int temp = arr[i];
      int j;
      for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
        arr[j] = arr[j - gap];
      }
      arr[j] = temp;
    }
  }
}

void merge(std::vector<int> &arr, int l, int m, int r) {
  int n1 = m - l + 1; // Kích thước mảng con trái
  int n2 = r - m;     // Kích thước mảng con phải

  std::vector<int> L(n1), R(n2);

  // Sao chép dữ liệu vào mảng tạm
  for (int i = 0; i < n1; i++) {
    L[i] = arr[l + i];
  }
  for (int i = 0; i < n2; i++) {
    R[i] = arr[m + 1 + i];
  }

  int i = 0, j = 0, k = l;

  // Hợp nhất hai mảng đã sắp xếp
  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  // Sao chép các phần tử còn lại của L[] nếu có
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  // Sao chép các phần tử còn lại của R[] nếu có
  while (j < n2) {
    arr[k] = R[j];
    j++;
    k++;
  }
}

void mergeSort(std::vector<int> &arr, int l, int r) {
  if (l >= r) {
    return;
  }
  int m = l + (r - l) / 2;
  mergeSort(arr, l, m);
  mergeSort(arr, m + 1, r);
  merge(arr, l, m, r);
}

int partition(std::vector<int> &arr, int low, int high) {
  int pivot = arr[high];
  int i = low - 1;
  for (int j = low; j < high; j++) {
    if (arr[j] < pivot) {
      i++;
      std::swap(arr[i], arr[j]);
    }
  }
  std::swap(arr[i + 1], arr[high]);
  printArray(arr);
  return i + 1;
}

void quickSort(std::vector<int> &arr, int low, int high) {
  if (low < high) {
    int pi = partition(arr, low, high);
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}

int main() {
  std::vector<int> arr = {3, 1, 5, 6, 4};
  std::cout << "Original array: ";
  printArray(arr);

  // mergeSort(arr, 0, arr.size() - 1);
  quickSort(arr, 0, arr.size() - 1);

  std::cout << "Sorted array: ";
  printArray(arr);

  return 0;
}
