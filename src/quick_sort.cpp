#include "quick_sort.hpp"

#include <cassert>  // assert

#include "partitioning.hpp"  // partition, median_of_three

namespace itis {

  void QuickSort::Sort(std::vector<int>& arr) const {
    quick_sort(arr, 0, static_cast<int>(arr.size()) - 1);
  }

  void QuickSort::quick_sort(std::vector<int>& arr, int start, int stop) const {
    assert(start >= 0);

    if (start >= stop) {
      return;
    }

    // вычисляем индекс опорного элемента
    int pivot_index = median_of_three(arr, start, stop);

    // производим разбиение относительно опорного элемента
    int temp = partition(arr, start, stop, pivot_index);
    // рекурсивно повторяем процедуру над левой и правой частью
    quick_sort(arr, start, temp - 1);
    quick_sort(arr, temp + 1, stop);
  }

}  // namespace itis
