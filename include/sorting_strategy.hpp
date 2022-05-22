#pragma once

#include <vector>

namespace itis {

  struct SortingStrategy {

    virtual ~SortingStrategy() = default;

    /**
     * Сортировка массива в порядке неубывания.
     *
     * @param arr - массив элементов
     */
    virtual void Sort(std::vector<int> &arr) = 0;
  };

}  // namespace itis
