#include <math.h>

#include <vector>

bool binary_search(std::vector<int> &arr, int target) {
  int left = 0;
  int right = arr.size();

  while (left < right) {
    auto m = floor(left + (right - left) / 2);
    if (arr[m] == target) {
      return true;
    }
    if (target < arr[m]) {
      right = m;
    }
    if (target > arr[m]) {
      left = m + 1;
    }
  };

  return false;
};
