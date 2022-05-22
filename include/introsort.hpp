#pragma once

#include "vector"
#include "sorting_strategy.hpp"

namespace itis {

  struct IntroSort final : SortingStrategy {

    /**
       * Реализация рекурсивного алгоритма быстрой сортировки (Quick Sort).
       *
       * Сложность ~ от O(n * log n) до O(n^2).
       * Элементы массива сортируются в порядке неубывания.
       *
       * @param arr - массив элементов
       */
    void Sort(std::vector<int>& arr) override;

   private:
    /**
       * Вычисление середины области, заданной левой и правой индексами.
       *
       * @param start - индекс левой границы (включительно)
       * @param stop - индекс правой границы (включительно)
       * @return индекс середины области
       */
    inline constexpr int middle_of(int start, int stop) {
      return start + (stop - start) / 2;
    }

    /**
     * Двоичный поиск позиции вставки элемента в левый подмассив.
     *
     * @param arr - массив элементов
     * @param index - текущая позиция вставляемого элемента
     * @return позиция вставки элемента
     */
    int binary_search(const std::vector<int>& arr, int begin, int index);

    /**
       * Реализация алгоритма сортировки вставками.
       *
       * Сложность ~ от O(n) до O(n^2).
       *
       * @param arr - массив элементов
       */
    void InsertionSort(std::vector<int>& arr, int start, int stop);

    /**
       * Построение максимальной двоичной кучи.
       *
       * Сложность ~ O(n).
       *
       * Перемещение элементов входного массива таким образом,
       * чтобы массив удовлетворял свойствам максимальной двоичной кучи.
       *
       * @param arr - массив элементов
       */
    void BuildMaxHeap(std::vector<int>& arr, int start, int stop);

    /**
       * Итеративная реализация спуска элемента вниз по двоичной куче.
       *
       * @param arr - массив элементов
       * @param heap_size - размер двоичной кучи (от 0 до heap_size - 1)
       * @param index индекс спускаемого элемента
       */
    void Heapify(std::vector<int>& arr, int heap_size, int start, int index);

    // вспомогательные методы для вычисления индексов в двоичной куче
    int Parent(int index);
    int LeftChild(int index);
    int RightChild(int index);

    /**
       * Реализация итеративного алгоритма пирамидальной сортировки (Heap Sort).
       *
       * Сложность ~ O(n * log n).
       *
       * Элементы массива сортируются в порядке неубывания.
       * В реализации используется максимальная двоичная куча.
       *
       * @param arr - массив элементов
       */
    void HeapSort(std::vector<int>& arr, int start, int stop);

    /**
     * Вспомогательная метод для реализации интроспективной сортировки
     * @param arr - массив элементов
     * @param start - индекс начала сортируемого участка вектора
     * @param stop - индекс конца сортируемого участка вектора
     * @param depth_limit - лимит рекурсивных вызовов
     */
    void IntroSortUtil(std::vector<int>& arr, int start, int stop, int depth_limit);
  };
}  // namespace itis
