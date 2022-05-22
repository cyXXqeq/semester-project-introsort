#include "introsort.hpp"

#include <cassert>  // assert
#include "partitioning.hpp"  // partition, median_of_three


namespace itis {

  int IntroSort::binary_search(const std::vector<int>& arr, int begin, int index) {

    // начало, конец и середина области поиска места для вставки [0, index - 1]
    int start = begin;
    int stop = index;
    int middle = IntroSort::middle_of(start, stop);

    // ищем до тех пор, пока границы не схлопнулись
    while (start <= stop) {

      // возвращаем позицию для вставки
      if (arr[index] == arr[middle]) {
        return middle;
      }

      // обновляем границы области поиска
      if (arr[index] < arr[middle]) {
        stop = middle - 1;
      } else {
        start = middle + 1;
      }

      // обновляем середину области поиска
      middle = middle_of(start, stop);
    }

    // в конечном счете возвращаем начало последней области поиска
    return start;
  }

  void IntroSort::InsertionSort(std::vector<int>& arr, int start, int stop) {
    // - проходимся по элементам, начиная со второго
    // - после каждой итерации, слева от index будет формироваться отсортированный массив
    // - первый элемент слева считается отсортированным
    for (int index = start + 1; index <= stop; index++) {

      // поиск индекса для вставки элемента с индексом index в область [0, index - 1]
      int ins_index = binary_search(arr, start, index);

      // если индекс вставки не совпадает с текущей позицией элемента,
      // производим вставку элемента на вычисленную позицию
      if (ins_index != index) {
        int temp = arr[index];
        for (int i = index; i > ins_index; i--) {
          arr[i] = arr[i - 1];
        }
        arr[ins_index] = temp;
      }
    }
  }

  int median_of_three(const std::vector<int>& arr, int start, int stop) {
    assert(!arr.empty() && start >= 0 && stop < arr.size() && start <= stop);

    // вычисляем размер области
    int size = stop - start + 1;

    // В случае отсутствия как минимум 3 элементов в указанной области,
    // возвращаем индекс правой границы.
    if (size < 3) {
      return stop;
    }

    // вычисляем индекс середины заданной области
    int middle = middle_of(start, stop);

    // поиск медианы среди трех элементов по индексам start, middle и stop
    if (arr[start] <= arr[middle] and arr[start] >= arr[stop]
        or arr[start] >= arr[middle] and arr[start] <= arr[stop]) {
      return start;
    }
    if (arr[middle] <= arr[start] and arr[middle] >= arr[stop]
        or arr[middle] >= arr[start] and arr[middle] <= arr[stop]) {
      return middle;
    }
    if (arr[stop] <= arr[middle] and arr[stop] >= arr[start]
        or arr[stop] >= arr[middle] and arr[stop] <= arr[start]) {
      return stop;
    }

    return -1;
  }

  int partition(std::vector<int>& arr, int start, int stop, int pivot) {
    assert(pivot >= start && pivot <= stop);
    assert(!arr.empty() && start >= 0 && stop < static_cast<int>(arr.size()) && start <= stop);

    // значение опорного элемента
    int pivot_value = arr[pivot];

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
    return curr_pivot_index;
  }

  void IntroSort::BuildMaxHeap(std::vector<int>& arr, int start, int stop) {
    int size = stop - start + 1;

    for (int i = Parent(size) + start; i >= start; i--) {
      Heapify(arr, size, start, i);
    }
  }

  void IntroSort::Heapify(std::vector<int>& arr, int heap_size, int start, int index) {
    assert(heap_size >= 0 && heap_size <= static_cast<int>(arr.size()) && index >= 0);

    int largest = index;
    int temp = index;
    bool done = false;
    while (!done) {
      // вычисляем индексы потомков для текущего элемента
      int left_child = LeftChild(temp - start) + start;
      int right_child = RightChild(temp - start) + start;
      // поиск наибольшего элемента среди текущего элемента и его потомков
      if (left_child < heap_size + start and arr[largest] < arr[left_child]) {
        largest = left_child;
      }
      if (right_child < heap_size + start and arr[largest] < arr[right_child]) {
        largest = right_child;
      }
      // если текущий элемент больше своих потомков, то он находится на правильном месте (свойство макс. кучи)
      if (largest != temp) {
        std::swap(arr[largest], arr[temp]);
        temp = largest;
      } else {
        done = true;
      }
    }
  }

  int IntroSort::Parent(int index) {
    assert(index >= 0);
    return index / 2 - 1;
  }

  int IntroSort::LeftChild(int index) {
    assert(index >= 0);
    return 2 * index + 1;
  }

  int IntroSort::RightChild(int index) {
    assert(index >= 0);
    return 2 * index + 2;
  }

  void IntroSort::HeapSort(std::vector<int>& arr, int start, int stop) {
    // строим двоичную кучу
    BuildMaxHeap(arr, start, stop);

    // обходим элементы кучи с конца до корня (не включительно)
    for (int index = stop; index > start; index--) {
      // обмениваем местами корень (максимальный элемент) и последний элемент кучи
      std::swap(arr[start], arr[index]);

      // спускаем новый корневой узел вниз
      Heapify(arr, index - start, start, start);
    }
  }

  void IntroSort::IntroSortUtil(std::vector<int>& arr, int start, int stop, int depth_limit) {
    int size = stop - start + 1;

    if (start >= stop) {
      return;
    }

    if (size < 16) {
      InsertionSort(arr, start, stop);
      return;
    }
    if (depth_limit == 0) {
      HeapSort(arr, start, stop);
      return;
    }

    int pivot = median_of_three(arr, start, stop);

    int partition_point = partition(arr, start, stop, pivot);
    IntroSortUtil(arr, start, partition_point - 1, depth_limit - 1);
    IntroSortUtil(arr, partition_point + 1, stop, depth_limit - 1);
  }

  void IntroSort::Sort(std::vector<int>& arr) {
    int depth_limit = 2 * static_cast<int>(log(static_cast<int>(arr.size())));

    IntroSortUtil(arr, 0, static_cast<int>(arr.size()) - 1, depth_limit);
  }
}  // namespace itis
