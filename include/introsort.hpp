#pragma once

#include "sorting_strategy.hpp"

namespace itis {
  int middle_of(int start, int stop);

  int binary_search(int arr[], int* begin, int index);

  void InsertionSort(int arr[], int* begin, int* end);

  int* median_of_three(int* start, int* middle, int* stop);

  int* partition(int arr[], int start, int stop, int pivot);

  void IntroSortUtil(int arr[], int *begin, int *end, int depth_limit);

  void IntroSort(int arr[], int *begin, int *end);
}
