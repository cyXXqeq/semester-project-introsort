#include "introsort.hpp"
#include "bits/stdc++.h"
#include "insertion_sort.hpp"
#include "heap_sort.hpp"

namespace itis {

  int middle_of(int start, int stop) {
    return start + (stop - start) / 2;
  }

  int binary_search(int arr[], int* begin, int index) {

    // начало, конец и середина области поиска места для вставки [0, index - 1]
    int start = begin - arr;
    int stop = index;
    int middle = middle_of(start, stop);

    // ищем до тех пор, пока границы не схлопнулись
    while (start <= stop) {

      // возвращаем позицию для вставки
      if (arr[index] == arr[middle]) {
        return middle;
      }

      // обновляем границы области поиска
      if (arr[index] < arr[middle]) {
        stop = middle - 1;
      }
      else {
        start = middle + 1;
      }

      // обновляем середину области поиска
      middle = middle_of(start, stop);
    }

    // в конечном счете возвращаем начало последней области поиска
    return start;
  }

  void InsertionSort(int arr[], int* begin, int* end) {
    int left = begin - arr;
    int right = end - arr;

    // - проходимся по элементам, начиная со второго
    // - после каждой итерации, слева от index будет формироваться отсортированный массив
    // - первый элемент слева считается отсортированным
    for (int index = left; index <= right; index++) {

      // поиск индекса для вставки элемента с индексом index в область [0, index - 1]
      const int ins_index = binary_search(arr, begin, index);

      // если индекс вставки не совпадает с текущей позицией элемента,
      // производим вставку элемента на вычисленную позицию
      if (ins_index != index) {
        int temp = arr[index];
        for (int i = index; i > ins_index; i--) {
          arr[i] = arr[i-1];
        }
        arr[ins_index] = temp;
      }
    }
  }

  int* median_of_three(int* start, int* middle, int* stop) {
    // поиск медианы среди трех элементов по индексам start, middle и stop
    if (*start <= *middle and *start >= *stop or *start >= *middle and *start <= *stop) {
      return start;
    }
    if (*middle <= *start and *middle >= *stop or *middle >= *start and *middle <= *stop) {
      return middle;
    }
    if (*stop <= *middle and *stop >= *start or *stop >= *middle and *stop <= *start) {
      return stop;
    }
  }

  int* partition(int arr[], int start, int stop, int pivot) {
    // значение опорного элемента
    const int pivot_value = arr[pivot];

    // переместить опорный элемент в конец
    std::swap(arr[pivot], arr[stop]);

    // индекс опорного элемента (будет вычисляться далее, изначально находится в начале области)
    int curr_pivot_index = start;

    // вычисление индекса опорного элемента и перемещение элементов по правилу разбиения
    for (int index = start; index < stop; index++) {

      if (arr[index] < pivot_value) {
        std::swap(arr[curr_pivot_index], arr[index]);
        curr_pivot_index++;
      }
    }

    // разбиение завершилось, перемещаем выбранный опорный элемент на вычисленное ранее место
    std::swap(arr[curr_pivot_index], arr[stop]);

    // возвращаем индекс опорного элемента
    int* partition_point = arr + curr_pivot_index;
    return partition_point;
  }

  void IntroSortUtil(int arr[], int *begin, int *end, int depth_limit) {
    int size = end - begin;

    if (size < 16) {
      InsertionSort(arr, begin, end);
      return ;
    }
    if (depth_limit == 0)
    {
      std::make_heap(begin, end+1);
      std::sort_heap(begin, end+1);
      return;
    }

    int* pivot = median_of_three(begin, begin+size/2, end);

    std::swap(arr[pivot-arr], arr[end-arr]);

    int* partition_point = partition(arr, begin-arr, end-arr, pivot-arr);
    IntroSortUtil(arr, begin, partition_point-1, depth_limit - 1);
    IntroSortUtil(arr, partition_point + 1, end, depth_limit - 1);
  }

  void IntroSort(int arr[], int *begin, int *end) {
    int depth_limit = 2 * log(end-begin);

    IntroSortUtil(arr, begin, end, depth_limit);
  }
}