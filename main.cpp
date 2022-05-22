#include <iostream>

#include "introsort.hpp"
#include "quick_sort.hpp"

using namespace itis;

int main(int argc, char *argv[]) {
  std::vector<int> arr = {337, 295, 33, 302, 235, 379, 146, 240, 220, 128, 485, 276, 225, 383, 490, 489, 343, 86, 444, 449, 248, 71, 419, 438, 220, 36, 283, 275, 442, 394, 242, 395, 150, 379, 254, 74, 280, 283, 461, 382, 474, 190, 64, 470, 343, 384, 496, 42, 62, 41, 448, 495, 453, 359, 310, 124, 20, 174, 284, 356, 327, 431, 204, 20, 342, 445, 496, 270, 230, 399, 449, 101, 166, 204, 301, 176, 437, 217, 497, 55, 488, 5, 110, 35, 379, 174, 494, 224, 278, 387, 382, 75, 31, 206, 450, 171, 286, 430, 465, 132};
  std::cout << arr.size() << std::endl;
  IntroSort introSort;
  QuickSort quickSort;
  quickSort.Sort(arr);
  for (int i = 0; i<100; i++) {
    std::cout << i<<"-"<<arr[i] << " ";
  }
  std::cout << arr.size() << std::endl;


  return 0;
}