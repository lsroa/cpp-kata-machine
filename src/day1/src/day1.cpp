#include <vector>

void bubble_sort(std::vector<int> &arr) {
  for (int j = arr.size() - 1; j >= 0; j--) {
    for (int i = 0; i < j; i++) {
      if (arr[i] > arr[i + 1]) {
        auto tmp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = tmp;
      }
    }
  }
};
